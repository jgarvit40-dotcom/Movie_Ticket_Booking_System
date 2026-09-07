#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "01_Movie.cpp"
#include "02_Seat.cpp"
#include "03_Screen.cpp"
#include "04_Cinema.cpp"
#include "05_Show.cpp"
#include "06_ShowSeat.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "10_PaymentTypes.cpp"
#include "11_PriceCalculator.cpp"
#include "12_TicketPrinter.cpp"
#include "13_BookingService.cpp"
using namespace std;

vector<string> splitSeats(const string& input) {
    vector<string> seatList;
    stringstream stream(input);
    string seat;

    while (getline(stream, seat, ',')) {
        while (!seat.empty() && seat.front() == ' ')
            seat.erase(seat.begin());

        while (!seat.empty() && seat.back() == ' ')
            seat.pop_back();

        if (!seat.empty())
            seatList.push_back(seat);
    }

    return seatList;
}

int main() {
    Cinema cinema("PVR Dehradun");

    Screen screen1("Screen-1");
    screen1.addSeat(Seat("A1", SeatType::SILVER));
    screen1.addSeat(Seat("A2", SeatType::SILVER));
    screen1.addSeat(Seat("A3", SeatType::SILVER));
    screen1.addSeat(Seat("A4", SeatType::SILVER));
    screen1.addSeat(Seat("B1", SeatType::GOLD));
    screen1.addSeat(Seat("B2", SeatType::GOLD));
    screen1.addSeat(Seat("B3", SeatType::GOLD));
    screen1.addSeat(Seat("C1", SeatType::PLATINUM));
    screen1.addSeat(Seat("C2", SeatType::PLATINUM));

    Screen screen2("Screen-2");
    screen2.addSeat(Seat("A1", SeatType::SILVER));
    screen2.addSeat(Seat("A2", SeatType::SILVER));
    screen2.addSeat(Seat("B1", SeatType::GOLD));
    screen2.addSeat(Seat("B2", SeatType::GOLD));

    cinema.addScreen(screen1);
    cinema.addScreen(screen2);

    Movie movie1("3 Idiots", "Hindi", 170);
    Movie movie2("Interstellar", "English", 169);

    vector<Movie*> movieList = { &movie1, &movie2 };

    vector<Show> showList;

    showList.push_back(
        Show("S1", &movie1, &cinema.getScreens()[0], "06:00 PM")
    );

    showList.push_back(
        Show("S2", &movie1, &cinema.getScreens()[1], "09:00 PM")
    );

    showList.push_back(
        Show("S3", &movie2, &cinema.getScreens()[1], "10:00 PM")
    );

    BookingService bookingService;
    Customer customer("Kritika", "9999999999");

    int choice;

    do {
        cout << "\n===== MOVIE TICKET BOOKING =====" << endl;
        cout << "1. Movies  2. Book  3. Cancel  4. My tickets  0. Exit" << endl;
        cout << "Choose: ";

        if (!(cin >> choice)) {
            cout << "  Invalid input." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            cout << endl;

            for (size_t i = 0; i < movieList.size(); i++) {
                cout << "  [" << i + 1 << "] "
                     << movieList[i]->getTitle() << "\t"
                     << movieList[i]->getLanguage() << "\t"
                     << movieList[i]->getDurationMin() << " min" << endl;
            }

        } else if (choice == 2) {
            cout << endl;

            for (size_t i = 0; i < movieList.size(); i++) {
                cout << "  [" << i + 1 << "] "
                     << movieList[i]->getTitle() << endl;
            }

            cout << "Choose movie: ";

            int movieChoice;

            if (!(cin >> movieChoice) ||
                movieChoice < 1 ||
                movieChoice > (int)movieList.size()) {

                cout << "  Invalid movie choice." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            Movie* selectedMovie = movieList[movieChoice - 1];

            vector<Show*> availableShows;

            for (auto& show : showList) {
                if (show.getMovie() == selectedMovie)
                    availableShows.push_back(&show);
            }

            if (availableShows.empty()) {
                cout << "  No shows available for this movie." << endl;
                continue;
            }

            for (size_t i = 0; i < availableShows.size(); i++) {
                cout << "  [" << i + 1 << "] "
                     << availableShows[i]->getScreen()->getScreenName()
                     << "\t"
                     << availableShows[i]->getStartTime() << endl;
            }

            cout << "Choose show: ";

            int showChoice;

            if (!(cin >> showChoice) ||
                showChoice < 1 ||
                showChoice > (int)availableShows.size()) {

                cout << "  Invalid show choice." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            Show* selectedShow = availableShows[showChoice - 1];

            selectedShow->printSeatLayout();

            cin.ignore();

            cout << "\nSeats (e.g. A1,B2): ";

            string seatInput;
            getline(cin, seatInput);

            vector<string> seatNumbers = splitSeats(seatInput);

            if (seatNumbers.empty()) {
                cout << "  No seats entered." << endl;
                continue;
            }

            Booking* booking = bookingService.createBooking(
                selectedShow,
                &customer,
                seatNumbers
            );

            if (booking == nullptr) {
                cout << "  One or more seats are invalid or already booked."
                     << " Booking rejected." << endl;
                continue;
            }

            cout << endl;

            for (auto* showSeat : booking->getSeats()) {
                cout << "  "
                     << showSeat->getSeatNumber()
                     << " "
                     << showSeat->getTypeName()
                     << "\tRs."
                     << PriceCalculator::priceOf(showSeat->getType())
                     << endl;
            }

            cout << "  TOTAL\t\tRs."
                 << booking->getTotalAmount() << endl;

            cout << "\nPay by: 1.UPI  2.Card  3.Cash > ";

            int paymentChoice;

            if (!(cin >> paymentChoice)) {
                cin.clear();
                cin.ignore(1000, '\n');
                paymentChoice = 0;
            }

            Payment* payment = nullptr;

            if (paymentChoice == 1)
                payment = new UpiPayment();
            else if (paymentChoice == 2)
                payment = new CardPayment();
            else if (paymentChoice == 3)
                payment = new CashPayment();
            else {
                cout << "  Invalid payment choice."
                     << " Booking not confirmed." << endl;
                continue;
            }

            bool paymentSuccessful =
                bookingService.payAndConfirm(booking, payment);

            delete payment;

            if (paymentSuccessful) {
                TicketPrinter::printTicket(*booking);
            } else {
                cout << "  Payment failed. Booking not confirmed; "
                     << "seats released." << endl;
            }

        } else if (choice == 3) {
            cin.ignore();

            cout << "Enter Booking ID to cancel: ";

            string bookingId;
            getline(cin, bookingId);

            if (bookingService.cancelBooking(bookingId)) {
                cout << "  Booking " << bookingId
                     << " cancelled. Seats are now available." << endl;
            } else {
                cout << "  Booking not found or not eligible "
                     << "for cancellation." << endl;
            }

        } else if (choice == 4) {
            cout << endl;

            for (auto& booking : bookingService.getAllBookings()) {
                cout << "  "
                     << booking.getBookingId() << "  "
                     << booking.getShow()->getMovie()->getTitle() << "  "
                     << "Rs." << booking.getTotalAmount() << "  "
                     << booking.getStatusName() << endl;
            }

        } else if (choice != 0) {
            cout << "  Invalid menu choice." << endl;
        }

    } while (choice != 0);

    cout << "Thank you for visiting "
         << cinema.getName() << "!" << endl;

    return 0;
}

#ifndef TICKETPRINTER_CPP
#define TICKETPRINTER_CPP

#include <iostream>
#include "08_Booking.cpp"
using namespace std;

class TicketPrinter {
public:
    static void printTicket(Booking& booking) {
        cout << "\n  ================ TICKET ================" << endl;
        cout << "  Booking ID : " << booking.getBookingId() << endl;
        cout << "  Movie      : " << booking.getShow()->getMovie()->getTitle() << endl;
        cout << "  Screen     : "
             << booking.getShow()->getScreen()->getScreenName()
             << "   " << booking.getShow()->getStartTime() << endl;

        cout << "  Seats      : ";

        for (size_t i = 0; i < booking.getSeats().size(); i++) {
            cout << booking.getSeats()[i]->getSeatNumber();

            if (i != booking.getSeats().size() - 1) {
                cout << ", ";
            }
        }

        cout << endl;

        cout << "  Amount     : Rs." << booking.getTotalAmount()
             << "     Status: " << booking.getStatusName() << endl;

        cout << "  =========================================" << endl;
    }
};

#endif

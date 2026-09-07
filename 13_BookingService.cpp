#ifndef BOOKINGSERVICE_CPP
#define BOOKINGSERVICE_CPP

#include <vector>
#include <string>
#include "05_Show.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "11_PriceCalculator.cpp"
using namespace std;

class BookingService {
private:
    vector<Booking> bookingList;
    static int nextBookingId;

    string generateBookingId() {
        return "BK" + to_string(1000 + nextBookingId++);
    }

public:
    Booking* createBooking(Show* show, Customer* customer,
                           const vector<string>& seatNumbers) {
        vector<ShowSeat*> selectedSeats;

        for (auto& seatNumber : seatNumbers) {
            ShowSeat* showSeat = show->findSeat(seatNumber);

            if (showSeat == nullptr || !showSeat->isAvailable()) {
                return nullptr;
            }

            selectedSeats.push_back(showSeat);
        }

        double totalPrice = PriceCalculator::calculateTotal(selectedSeats);
        string newBookingId = generateBookingId();

        bookingList.push_back(
            Booking(newBookingId, show, customer, selectedSeats, totalPrice)
        );

        return &bookingList.back();
    }

    bool payAndConfirm(Booking* booking, Payment* payment) {
        bool paymentSuccessful = payment->pay(booking->getTotalAmount());

        if (paymentSuccessful) {
            for (auto* showSeat : booking->getSeats()) {
                showSeat->markBooked();
            }

            booking->confirm(payment->getMethodName());
        } else {
            booking->fail();
        }

        return paymentSuccessful;
    }

    bool cancelBooking(const string& bookingId) {
        for (auto& booking : bookingList) {
            if (booking.getBookingId() == bookingId &&
                booking.getStatus() == BookingStatus::CONFIRMED) {

                for (auto* showSeat : booking.getSeats()) {
                    showSeat->markAvailable();
                }

                booking.cancel();
                return true;
            }
        }

        return false;
    }

    Booking* findBooking(const string& bookingId) {
        for (auto& booking : bookingList) {
            if (booking.getBookingId() == bookingId) {
                return &booking;
            }
        }

        return nullptr;
    }

    vector<Booking>& getAllBookings() {
        return bookingList;
    }
};

int BookingService::nextBookingId = 1;

#endif

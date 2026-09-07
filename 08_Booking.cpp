#ifndef BOOKING_CPP
#define BOOKING_CPP

#include <vector>
#include <string>
#include "05_Show.cpp"
#include "06_ShowSeat.cpp"
#include "07_Customer.cpp"
using namespace std;

enum class BookingStatus { PENDING, CONFIRMED, FAILED, CANCELLED };

class Booking {
private:
    string bookingId;
    Show* showInfo;
    Customer* customerInfo;
    vector<ShowSeat*> bookedSeats;
    double totalAmount;
    BookingStatus bookingStatus;
    string paymentMethod;

public:
    Booking(string id, Show* showPtr, Customer* customerPtr,
            vector<ShowSeat*> seats, double amount)
        : bookingId(id), showInfo(showPtr), customerInfo(customerPtr),
          bookedSeats(seats), totalAmount(amount),
          bookingStatus(BookingStatus::PENDING) {}

    string getBookingId() const {
        return bookingId;
    }

    Show* getShow() const {
        return showInfo;
    }

    Customer* getCustomer() const {
        return customerInfo;
    }

    vector<ShowSeat*>& getSeats() {
        return bookedSeats;
    }

    double getTotalAmount() const {
        return totalAmount;
    }

    BookingStatus getStatus() const {
        return bookingStatus;
    }

    string getPaymentMethod() const {
        return paymentMethod;
    }

    void confirm(string method) {
        bookingStatus = BookingStatus::CONFIRMED;
        paymentMethod = method;
    }

    void fail() {
        bookingStatus = BookingStatus::FAILED;
    }

    void cancel() {
        bookingStatus = BookingStatus::CANCELLED;
    }

    string getStatusName() const {
        switch (bookingStatus) {
            case BookingStatus::PENDING:
                return "PENDING";
            case BookingStatus::CONFIRMED:
                return "CONFIRMED";
            case BookingStatus::FAILED:
                return "FAILED";
            case BookingStatus::CANCELLED:
                return "CANCELLED";
        }

        return "UNKNOWN";
    }
};

#endif

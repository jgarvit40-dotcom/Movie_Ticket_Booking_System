#ifndef SHOWSEAT_CPP
#define SHOWSEAT_CPP

#include <string>
#include "02_Seat.cpp"
using namespace std;

enum class SeatStatus { AVAILABLE, BOOKED };

class ShowSeat {
private:
    Seat seatInfo;
    SeatStatus currentStatus;

public:
    ShowSeat(Seat seat)
        : seatInfo(seat), currentStatus(SeatStatus::AVAILABLE) {}

    string getSeatNumber() const {
        return seatInfo.getSeatNumber();
    }

    SeatType getType() const {
        return seatInfo.getType();
    }

    string getTypeName() const {
        return seatInfo.getTypeName();
    }

    bool isAvailable() const {
        return currentStatus == SeatStatus::AVAILABLE;
    }

    void markBooked() {
        currentStatus = SeatStatus::BOOKED;
    }

    void markAvailable() {
        currentStatus = SeatStatus::AVAILABLE;
    }
};

#endif

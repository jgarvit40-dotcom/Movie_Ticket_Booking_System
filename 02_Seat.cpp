#ifndef SEAT_CPP
#define SEAT_CPP

#include <string>
using namespace std;

enum class SeatType { SILVER, GOLD, PLATINUM };

class Seat {
private:
    string seatId;
    SeatType seatCategory;

public:
    Seat(string id, SeatType category)
        : seatId(id), seatCategory(category) {}

    string getSeatNumber() const {
        return seatId;
    }

    SeatType getType() const {
        return seatCategory;
    }

    string getTypeName() const {
        switch (seatCategory) {
            case SeatType::SILVER:
                return "SILVER";
            case SeatType::GOLD:
                return "GOLD";
            case SeatType::PLATINUM:
                return "PLATINUM";
        }
        return "UNKNOWN";
    }
};

#endif

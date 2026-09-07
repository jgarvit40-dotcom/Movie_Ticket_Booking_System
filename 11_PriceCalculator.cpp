#ifndef PRICECALCULATOR_CPP
#define PRICECALCULATOR_CPP

#include <vector>
#include "06_ShowSeat.cpp"
using namespace std;

const double SILVER_PRICE = 150.0;
const double GOLD_PRICE = 250.0;
const double PLATINUM_PRICE = 400.0;

class PriceCalculator {
public:
    static double priceOf(SeatType seatType) {
        switch (seatType) {
            case SeatType::SILVER:
                return SILVER_PRICE;
            case SeatType::GOLD:
                return GOLD_PRICE;
            case SeatType::PLATINUM:
                return PLATINUM_PRICE;
        }

        return 0.0;
    }

    static double calculateTotal(const vector<ShowSeat*>& selectedSeats) {
        double totalPrice = 0.0;

        for (auto* seat : selectedSeats) {
            totalPrice += priceOf(seat->getType());
        }

        return totalPrice;
    }
};

#endif

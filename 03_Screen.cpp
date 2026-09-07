#ifndef SCREEN_CPP
#define SCREEN_CPP

#include <vector>
#include <string>
#include "02_Seat.cpp"
using namespace std;

// Screen: knows its name and OWNS its seats (composition - Screen 1 *-- 1..* Seat).
// Must NOT know about movies, shows, or bookings.
class Screen {
private:
    string screenName;
    vector<Seat> seats;

public:
    Screen(string screenName) : screenName(screenName) {}

    void addSeat(const Seat& seat) {
        seats.push_back(seat);
    }

    string getScreenName() const { return screenName; }
    vector<Seat>& getSeats() { return seats; }
};

#endif

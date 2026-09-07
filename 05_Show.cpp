#ifndef SHOW_CPP
#define SHOW_CPP

#include <vector>
#include <string>
#include <iostream>
#include "01_Movie.cpp"
#include "03_Screen.cpp"
#include "06_ShowSeat.cpp"
using namespace std;

class Show {
private:
    string showId;
    Movie* movie;
    Screen* screen;
    string showTime;
    vector<ShowSeat> seatsForShow;

public:
    Show(string id, Movie* moviePtr, Screen* screenPtr, string time)
        : showId(id), movie(moviePtr), screen(screenPtr), showTime(time) {
        
        for (auto& seat : screen->getSeats()) {
            seatsForShow.push_back(ShowSeat(seat));
        }
    }

    string getShowId() const {
        return showId;
    }

    Movie* getMovie() const {
        return movie;
    }

    Screen* getScreen() const {
        return screen;
    }

    string getStartTime() const {
        return showTime;
    }

    vector<ShowSeat>& getShowSeats() {
        return seatsForShow;
    }

    ShowSeat* findSeat(const string& seatNumber) {
        for (auto& showSeat : seatsForShow) {
            if (showSeat.getSeatNumber() == seatNumber) {
                return &showSeat;
            }
        }
        return nullptr;
    }

    void printSeatLayout() {
        cout << "\n  " << screen->getScreenName() << "  " << showTime
             << "  |  " << movie->getTitle() << endl;

        SeatType seatTypes[3] = {
            SeatType::SILVER,
            SeatType::GOLD,
            SeatType::PLATINUM
        };

        string seatLabels[3] = {
            "SILVER  ",
            "GOLD    ",
            "PLATINUM"
        };

        for (int i = 0; i < 3; i++) {
            bool found = false;

            for (auto& showSeat : seatsForShow) {
                if (showSeat.getType() == seatTypes[i]) {
                    found = true;
                    break;
                }
            }

            if (!found)
                continue;

            cout << "  " << seatLabels[i] << " ";

            for (auto& showSeat : seatsForShow) {
                if (showSeat.getType() == seatTypes[i]) {
                    cout << showSeat.getSeatNumber()
                         << (showSeat.isAvailable() ? "[ ] " : "[X] ");
                }
            }

            cout << endl;
        }

        cout << "  ( [ ] = available   [X] = booked )" << endl;
    }
};

#endif

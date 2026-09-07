#ifndef CINEMA_CPP
#define CINEMA_CPP

#include <vector>
#include <string>
#include "03_Screen.cpp"
using namespace std;

class Cinema {
private:
    string cinemaName;
    vector<Screen> screenList;

public:
    Cinema(string name) : cinemaName(name) {}

    void addScreen(const Screen& newScreen) {
        screenList.push_back(newScreen);
    }

    string getName() const {
        return cinemaName;
    }

    vector<Screen>& getScreens() {
        return screenList;
    }
};

#endif

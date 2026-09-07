#ifndef MOVIE_CPP
#define MOVIE_CPP

#include <string>
using namespace std;

class Movie {
private:
    string movieTitle;
    string movieLanguage;
    int movieDuration;

public:
    Movie(string title, string language, int duration)
        : movieTitle(title), movieLanguage(language), movieDuration(duration) {}

    string getTitle() const {
        return movieTitle;
    }

    string getLanguage() const {
        return movieLanguage;
    }

    int getDurationMin() const {
        return movieDuration;
    }
};

#endif

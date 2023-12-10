#include "Time.h"
using namespace std;

Time::Time() : hour(0), minute(0) {}

void Time::setTime(int h, int m) {
    hour = (h >= 0 && h < 24);
    minute = (m >= 0 && m < 60);
}

void Time::printTime() {
    cout << setfill('0') << setw(2) << hour << ":"
        << setfill('0') << setw(2) << minute << endl;       //output formatting in a (00:00) format.
}

void Time::tick() {
    ++minute;
    if (minute >= 60) {
        minute = 0;
        ++hour;
        if (hour >= 24) {
            hour = 0;
        }
    }
}

#include "Time.h"

Time::Time() : hour(0), minute(0) {}

void Time::setTime(int h, int m) {
    if (h >= 0 && h < 24) hour = h;
    if (m >= 0 && m < 60) minute = m;
}


void Time::printTime() {
    std::cout << std::setfill('0') << std::setw(2) << hour << ":"
        << std::setfill('0') << std::setw(2) << minute << std::endl;       //output formatting in a (00:00) format.
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

int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }

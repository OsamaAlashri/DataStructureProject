#include "Time.h"

Time::Time() : hour(0), minute(0), second(0) {} // initialize seconds to 0

void Time::setTime(int h, int m, int s) {
    if (h >= 0 && h < 24) hour = h;
    if (m >= 0 && m < 60) minute = m;
    if (s >= 0 && s < 60) second = s; 
}

void Time::printTime() {
    std::cout << std::setfill('0') << std::setw(2) << hour << ":"
        << std::setfill('0') << std::setw(2) << minute << std::endl; 
}

void Time::tick() {
    ++second;
    if (second >= 60) {
        second = 0;
        ++minute;
        if (minute >= 60) {
            minute = 0;
            ++hour;
            if (hour >= 24) {
                hour = 0;
            }
        }
    }
}

int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; } 

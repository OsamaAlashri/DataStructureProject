#pragma once
#include <iostream>
#include <iomanip>

class Time {
    int hour;
    int minute;

public:
    Time();
    void setTime(int h, int m);
    void printTime();
    void tick();

    //getters
    int getHour()  const;
    int getMinute() const;
};

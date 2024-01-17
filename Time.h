#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Time {
    int hour;
    int minute;
    int second; 

public:
    Time();
    void setTime(int h, int m, int s); 
    void printTime();
    void tick();

    //getters
    int getHour()  const;
    int getMinute() const;
    int getSecond() const;
    int geTime() const;
};

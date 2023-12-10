#pragma once
#include "Time.h"
#include <string>

class Passengers {
    Time arrivalTime;
    Time getON_OFF;
    int startStation;
    int endStation;
    std::string type;

public:
    Passengers(const std::string& t, int& s, int& e, Time& arrival, Time& get_on_off);
    void setArrivalTime(Time t);
    void setGetOnOff(Time t);
    void setStartStation(int s);
    void setEndStation(int e);
    void setType(std::string t);
    Time getArrivalTime();
    Time getGetOnOff();
    int getStartStation();
    int getEndStation();
    std::string getType();
    int PassengerPriorty();
};

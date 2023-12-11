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

    //setters
    void setArrivalTime(Time t);
    void setGetOnOff(Time t);
    void setStartStation(int s);
    void setEndStation(int e);
    void setType(std::string t);

    //getters
    Time getArrivalTime() const;
    Time getGetOnOff() const;
    int getStartStation() const;
    int getEndStation() const;
    std::string getType() const;
    int PassengerPriorty() const;
};

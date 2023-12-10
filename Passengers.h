#pragma once
#include "Time.h"
#include <string>
class Passengers {
    Time arrivalTime;
    Time getON_OFF;
    int startStation;
    int endStation;
    string type;

public:
    // Setters
    void setArrivalTime(Time t) { arrivalTime = t; }
    void setGetOnOff(Time t) { getON_OFF = t; }
    void setStartStation(int s) { startStation = s; }
    void setEndStation(int e) { endStation = e; }
    void setType(std::string t) { type = t; }

    // Getters
    Time getArrivalTime() { return arrivalTime; }
    Time getGetOnOff() { return getON_OFF; }
    int getStartStation() { return startStation; }
    int getEndStation() { return endStation; }
    string getType() { return type; }

    int PassengerPriorty() {
        if (type == "SP") { return 2; }
        if (type == "NP") { return 1; }
    }

};
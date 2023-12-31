#pragma once
#include "Time.h"

enum class PassengerType
{
    NP = 1,
    Pregenant,
    POD,
    Aged,
    WP
};

class Passengers {
    Time arrivalTime;
    Time getON_OFF;
    int startStation;
    int endStation;
    PassengerType type;
    int ID;

public:
    Passengers(const PassengerType& type, int start, int end, Time& arrival, Time& get_on_off , int ID);

    //setters
    void setArrivalTime(Time time);
    void setGetOnOff(Time time);
    void setStartStation(int start);
    void setEndStation(int end);
    void setType(PassengerType type);
    void setID(int ID);

    //getters
    Time getArrivalTime() const ;
    Time getGetOnOff() const ;
    int getStartStation() const ;
    int getEndStation() const ;
    PassengerType getType() const ;
    int getID() const ;
};

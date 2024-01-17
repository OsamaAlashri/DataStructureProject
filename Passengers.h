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
    int MaxW;
    int waitingTime;
    string Type;
public:
    Passengers(const PassengerType& type, int start, int end, Time& arrival, Time& get_on_off, int ID, int WT, int MW);

    //setters
    void setArrivalTime(Time time);
    void setGetOnOff(Time time);
    void setStartStation(int start);
    void setEndStation(int end);
    void setType(PassengerType type);
    void setID(int ID);
    //New Phase2
    void setWaitingTime(int WT);
    void setMaxW(int MW);
    //End

    //getters
    Time getArrivalTime() const;
    Time getGetOnOff() const;
    int getStartStation() const;
    int getEndStation() const;
    PassengerType getType() const;
    int getID() const;

    string getPassengerType() const;

    //New Phase2
    int getWaitingTime() const;
    int getMaxW() const;
    void IncreaseWaitingTime(int time);
};
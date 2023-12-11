#pragma once
#include <string>
using namespace std;

class Event {
public:
    int id;
    string eventType;
    string passengerType;
    string eventTime;
    string startStation;
    string endStation;

    Event(const string& eventType, const string& passengerType, const string& eventTime, int id, const string& startStation, const string& endStation);

    virtual void Execute() = 0;

    
};

class ArrivalEvent : public Event {
public:
    ArrivalEvent(const string& passengerType, const string& eventTime, int id, const string& startStation, const string& endStation,const string& extraInfo);

    void Execute() override;

private:
    string extraInfo;
};

class LeaveEvent : public Event {
public:
    LeaveEvent(const string& eventTime, const string& startStation);

    void Execute() override;
};

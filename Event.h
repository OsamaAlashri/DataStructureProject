#pragma once

#include "Station.h"
#include "LinkedList.h"
#include <string>

using namespace std;

class Event
{

public:
    Time time;
    int id;
    Event(Time time, int id);

    virtual void execute() = 0;

    int geteventTime();
};

class ArrivalEvent : public Event
{
    string passenegerType;
    int startStation;
    int endStation;
    int priority;

public:
    ArrivalEvent(Time time, int id, string passenegerType, int startStation, int endStation, int priority = -1);

    void execute() override;
};

class LeaveEvent : public Event
{
public:
    LeaveEvent(Time time, int id);

    void execute() override;
};
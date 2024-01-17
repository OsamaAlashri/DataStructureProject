#pragma once

#include "Station.h"
#include "LinkedList.h"
#include <string>

using namespace std;

class Event
{

public:
    int eventTime;
    int id;
    Event(int eventTime, int id);

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
    ArrivalEvent(int eventTime, int id, string passenegerType, int startStation, int endStation, int priority = -1);

    void execute() override;
};

class LeaveEvent : public Event
{
public:
    LeaveEvent(int eventTime, int id);

    void execute() override;
};
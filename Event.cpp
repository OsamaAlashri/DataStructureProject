#include "Event.h"
#include<iostream>


//Parent Class
Event::Event(int eventTime, int id) : eventTime(eventTime), id(id) {}

int Event::geteventTime()
{
    return eventTime;
}

//Arival Event
ArrivalEvent::ArrivalEvent(int eventTime, int id, string passenegerType, int startStation, int endStation, int priority)
    : Event(eventTime, id), passenegerType(passenegerType), startStation(startStation), endStation(endStation), priority(priority) {}

void ArrivalEvent::execute() {
    std::cout << "Executing Arrival Event\n";
}

//Leave Event
LeaveEvent::LeaveEvent(int eventTime, int id) : Event(eventTime, id) {}

void LeaveEvent::execute() {
    std::cout << "Executing Leave Event\n";
}

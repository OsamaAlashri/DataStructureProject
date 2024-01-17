#include "Event.h"
#include<iostream>


//Parent Class
Event::Event(Time time, int id) : time(time), id(id) {}

int Event::geteventTime()
{
    return time.geTime();
}

//Arival Event
ArrivalEvent::ArrivalEvent(Time time, int id, string passenegerType, int startStation, int endStation, int priority)
    : Event(time, id), passenegerType(passenegerType), startStation(startStation), endStation(endStation), priority(priority) {}

void ArrivalEvent::execute() {
    std::cout << "Executing Arrival Event\n";
}

//Leave Event
LeaveEvent::LeaveEvent(Time time, int id) : Event(time, id) {}

void LeaveEvent::execute() {
    std::cout << "Executing Leave Event\n";
}

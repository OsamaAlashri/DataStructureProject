#include "Event.h"
#include <iostream>
using namespace std;

// Event 
Event::Event(const string& eventType, const string& passengerType, const string& eventTime, int id, const string& startStation, const string& endStation)
    : eventType(eventType), passengerType(passengerType), eventTime(eventTime), id(id), startStation(startStation), endStation(endStation) {}

// ArrivalEvent 
ArrivalEvent::ArrivalEvent(const string& passengerType, const string& eventTime, int id, const string& startStation, const string& endStation, const string& extraInfo)
    : Event("A", passengerType, eventTime, id, startStation, endStation), extraInfo(extraInfo) {}

void ArrivalEvent::Execute() {
    cout << "Executing Arrival Event\n";
}

// LeaveEvent 
LeaveEvent::LeaveEvent(const string& eventTime, const string& startStation)
    : Event("L", "", eventTime, 0, startStation, "") {}

void LeaveEvent::Execute() {
    cout << "Executing Leave Event\n";
}

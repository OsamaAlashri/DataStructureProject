#include "Passengers.h"

Passengers::Passengers(const PassengerType& t, int s, int e, Time& arrival, Time& get_on_off)
    : type(t), startStation(s), endStation(e), arrivalTime(arrival), getON_OFF(get_on_off) {}

void Passengers::setArrivalTime(Time t) { arrivalTime = t; }
void Passengers::setGetOnOff(Time t) { getON_OFF = t; }
void Passengers::setStartStation(int s) { startStation = s; }
void Passengers::setEndStation(int e) { endStation = e; }
void Passengers::setType(PassengerType t) { type = t; }

Time Passengers::getArrivalTime() const { return arrivalTime; }
Time Passengers::getGetOnOff() const { return getON_OFF; }
int Passengers::getStartStation() const { return startStation; }
int Passengers::getEndStation() const { return endStation; }
PassengerType Passengers::getType() const { return type; }

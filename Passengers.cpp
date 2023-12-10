#include "Passengers.h"

Passengers::Passengers(const std::string& t, int& s, int& e, Time& arrival, Time& get_on_off)
    : type(t), startStation(s), endStation(e), arrivalTime(arrival), getON_OFF(get_on_off) {}

void Passengers::setArrivalTime(Time t) { arrivalTime = t; }
void Passengers::setGetOnOff(Time t) { getON_OFF = t; }
void Passengers::setStartStation(int s) { startStation = s; }
void Passengers::setEndStation(int e) { endStation = e; }
void Passengers::setType(std::string t) { type = t; }

Time Passengers::getArrivalTime() { return arrivalTime; }
Time Passengers::getGetOnOff() { return getON_OFF; }
int Passengers::getStartStation() { return startStation; }
int Passengers::getEndStation() { return endStation; }
std::string Passengers::getType() { return type; }

int Passengers::PassengerPriorty() {
    if (type == "SP") { return 2; }
    if (type == "NP") { return 1; }
}

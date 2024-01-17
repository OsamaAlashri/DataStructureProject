#include "Passengers.h"

Passengers::Passengers(const PassengerType& t, int s, int e, Time& arrival, Time& get_on_off, int Idenfication, int WT, int MW)
    : type(t), startStation(s), endStation(e), arrivalTime(arrival), getON_OFF(get_on_off), ID(Idenfication), waitingTime(WT), MaxW(MW) {}

void Passengers::setArrivalTime(Time t) { arrivalTime = t; }
void Passengers::setGetOnOff(Time t) { getON_OFF = t; }
void Passengers::setStartStation(int s) { startStation = s; }
void Passengers::setEndStation(int e) { endStation = e; }
void Passengers::setType(PassengerType t) { type = t; }
void Passengers::setID(int Idenfication) { ID = Idenfication; }
//New Phase2
void Passengers::setWaitingTime(int WT) { waitingTime = WT; }
void Passengers::setMaxW(int MW) { MaxW = MW; }

Time Passengers::getArrivalTime() const { return arrivalTime; }
Time Passengers::getGetOnOff() const { return getON_OFF; }
int Passengers::getStartStation() const { return startStation; }
int Passengers::getEndStation() const { return endStation; }
PassengerType Passengers::getType() const { return type; }
int Passengers::getID() const { return ID; }
string Passengers::getPassengerType() const { return Type; }
//New Phase2
int Passengers::getWaitingTime() const { return waitingTime; }
int Passengers::getMaxW() const { return MaxW; }
void Passengers::IncreaseWaitingTime(int Time) {

}
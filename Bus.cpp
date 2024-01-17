#include "Bus.h"
#include "Time.h"
#include "Passengers.h"
#include "Queue.h"

Bus::Bus(const std::string& type, int& cap, int& j, const Time& checkup)
    : busType(type), capacity(cap), journeys(j), checkupTime(checkup) {};

PassengerType type;
void Bus::setBusType(const std::string& type) { busType = type; }
void Bus::setCapacity(int cap) { capacity = cap; }
void Bus::setJourneys(int j) { journeys = j; }
void Bus::setCheckupTime(Time checkup) { checkupTime = checkup; }
void Bus::setMovingTime(Time moving) { MovingTime = moving; }

std::string Bus::getBusType() const { return busType; }
int Bus::getCapacity() const { return capacity; }
int Bus::getJourneys() const { return journeys; }
Time Bus::getCheckupTime() const { return checkupTime; }
Time Bus::getMovingTime() const { return MovingTime; }

bool Bus::needsCheckup() const { return journeys >= limit; }


MBus::MBus(const std::string& type, int& cap, int& j, const Time& checkup)
    : Bus(type, cap, j, checkup) {}

void MBus::onboardPassenger(Passengers* Passenger) {


    if (type != PassengerType::WP) {
        for (int i = 0; i < StationNum; i++) {
            station[i].addPassenger(Passenger);
        }

    }
}

void MBus::offboardPassenger(Passengers* Passenger) {
    if (type != PassengerType::WP) {
        for (int i = 0; i < StationNum; i++) {
            station[i].removePassenger(Passenger);
        }

    }
}

WBus::WBus(const std::string& type, int& cap, int& j, const Time& checkup)
    : Bus(type, cap, j, checkup) {}

void WBus::onboardPassenger(Passengers* Passenger) {
    if (type == PassengerType::WP) {
        for (int i = 0; i < StationNum; i++) {
            station[i].addPassenger(Passenger);
        }

    }
}

void WBus::offboardPassenger(Passengers* Passenger) {
    if (type == PassengerType::WP) {
        for (int i = 0; i < StationNum; i++) {
            station[i].removePassenger(Passenger);
        }

    }
}

void MBus::GoForward() {
    if (station != nullptr && !station->WaitingPassengers()) {
        currentStation++;
    }
}

void MBus::GoBackward() {
    if (station != nullptr && !station->WaitingPassengers()) {
        currentStation--;
    }
}

void MBus::Remove_A_Pasenger(Passengers passenger) const
{
}

void WBus::GoForward() {
    if (station != nullptr && !station->WaitingPassengers()) {
        currentStation++;
    }
}

void WBus::GoBackward() {
    if (station != nullptr && !station->WaitingPassengers()) {
        currentStation--;
    }
}

void WBus::Remove_A_Pasenger(Passengers passenger) const
{
}

#include "Station.h"

Station::Station(int stationNum) : stationNumber(stationNum) {}

void Station::addBus(const Bus& bus) {
    availableBuses.add(bus);
}

void Station::removeBus(const Bus& bus) {
    availableBuses.remove(bus);
}

List<Bus> Station::getAvailableBuses() const {
    return availableBuses;
}

void Station::addPassenger(const Passengers& passenger) {
    waitingPassengers.add(passenger);
}

void Station::removePassenger(const Passengers& passenger) {
    waitingPassengers.remove(passenger);
}

List<Passengers> Station::getWaitingPassengers() const {
    return waitingPassengers;
}

void Station::unloadLoadPassengers() {

}



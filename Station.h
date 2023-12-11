#pragma once
#include "List.h"
#include "Bus.h"
#include "Passengers.h"
#include "Queue.h"

class Station {
private:
    int stationNumber;
    List<Passengers> waitingPassengers;
    List<Bus> availableBuses;
	int maxStations;

public:
    Station(int stationNum);

    void addBus(const Bus& bus);
    void removeBus(const Bus& bus);
    List<Bus> getAvailableBuses() const;

    void addPassenger(const Passengers& passenger);
    void removePassenger(const Passengers& passenger);
    List<Passengers> getWaitingPassengers() const;

    void unloadLoadPassengers();

	List<Passengers> Np; //normal person cal leave the queue after MaxW time (list is needed not queue)
	Queue<Passengers> Aged;
	Queue<Passengers> POD;
	Queue<Passengers> PW;
	Queue<Passengers> Wp;
	bool CheckTime();

};


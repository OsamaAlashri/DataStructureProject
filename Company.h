#ifndef COMPANY_H
#define COMPANY_H


#include <iostream>
#include <fstream>
#include <vector>
#include "Event.h"
#include "EventQueue.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Passengers.h"
#include "Station.h"
#include "Bus.h"

using namespace std;


class Company {
private:

	Time time;

	Station* stations;
	Queue<Event*> events;
	Queue<Passengers*> finishedPassengers;
	Queue<Bus*> checkupWheelBuses;
	Queue<Bus*> checkupMixedBuses;
	Queue<Bus*> movingBuses;
	Queue<Bus*> stationZero;
	vector <Bus*> movingbuses;

	Passengers* passenger = nullptr;

	string passengerType;
	string type;

	int maxWaitingTime;
	int promotedPassengers;
	int numberOfStations;
	int journiesBeforeCheckup, wBusCheckupPeriod, mBusCheckupPeriod;
	int gettingTime;
	int journeysBeforeCheckup;
	int boardingTime;
	int timestep;

	char eventType;

	int nextStation;

	int numStations;
	int timeBetweenStations;
	int totalWBusCount;
	int totalMBusCount;
	int wBusCapacity;
	int mBusCapacity;
	int tripsBeforeCheckup;
	int checkupDurationWBus;
	int checkupDurationMBus;
	int getOnOffTime;
	int totalPassengers;
	int numNormalPassengers;
	int numSpecialPassengers;
	int numWaitingPassengers;
	int totalBuses;
	int numWBus;
	int numMBus;
	int averageWaitingTime;
	int averageTripTime;
	int timenow;

		Station* stations;
		Queue<Event*> events;
		Queue<Passengers*> completedPassengers;
		Queue<Bus*> checkupWheelBuses;
		Queue<Bus*> checkupMixedBuses;
		Queue<Bus*> movingBuses;
		Queue<Bus*> stationZero;
		Queue<Bus*> movingbuses;
public:

	Company();

	
	Event* createArrivalEvent(ifstream& file);
	Event* createLeaveEvent(ifstream& file);
	void generateOutputFile();
	void startSimulation();

	void OPENFILE(const string& filename);
	void releasebus();
	void releaseFromCheckup(Queue<Bus*>& checkupBuses, Time checkupTime, Time timenow);
	void addBusesToStations(Time timestep);
    void addToCheckup(Bus* bus, Time timenow);
	void RemovePassenger(Bus* bus, Passengers* passengers);

};

#endif

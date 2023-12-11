#pragma once
#include "List.h"
#include "Passengers.h"
#include "Station.h"
#include "Time.h"
class Bus
{
	std::string busType;
	int capacity;
	int journeys;
	Time checkupTime;

public:

	List<Passengers> passengers;
	int numberOfTrips = 0; 
	Time busyTime;
	Time utilizationTime;
	Station* station = nullptr;
	// check purpose for the above lines

	Bus(const std::string& type, int& cap, int& j,const Time& checkup);

	//setters
	void setBusType(const std::string& type);
	void setCapacity(int cap);
	void setJourneys(int j);
	void setCheckupTime(Time checkup);

	//getters
	std::string getBusType() const;
	int getCapacity() const;
	int getJourneys() const;
	Time getCheckupTime() const;
	bool needsCheckup() const;
};

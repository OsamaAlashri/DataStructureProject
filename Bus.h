#pragma once
#include "List.h"
#include "Passengers.h"
#include "Station.h"
#include "Time.h"
class Bus
{
public:
	List<Passengers> passengers;
	int numberOfTrips=0;
	Time busyTime;
	Time utilizationTime;
	Station* station = nullptr;
	Bus();


};


#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Event.h"

using namespace std;

class Bus {};

class Company {
private:
    vector<Event*> eventsList;
    vector<Bus> busesList;

    //INPUT
    int numStations;
    int timeBetweenStations;
    int totalWBusCount;
    int totalMBusCount;
    int wBusCapacity;
    int mBusCapacity;
    int tripsBeforeCheckup;
    int checkupDurationWBus;
    int checkupDurationMBus;
    int maxWaitingTime;
    int getOnOffTime;

    //OUTPUT
    vector<string> outputLines; 
    int totalPassengers;
    int numNormalPassengers;
    int numSpecialPassengers;
    int numWaitingPassengers;
    int totalBuses;
    int numWBus;
    int numMBus;

    int averageWaitingTime;
    int averageTripTime;

    double percentageAutoPromoted;

    int averageBusyTime;
    double averageUtilization;

public:
    Company();
    void loadInitialData(const string& filename);
    void executeMinuteTasks();
    void produceOutputFile(const string& outputFilename);
};

#endif

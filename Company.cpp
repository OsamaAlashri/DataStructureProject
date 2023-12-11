#include "Company.h"


Company::Company() {
    
}

void Company::loadInitialData(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << filename << endl;
        return;
    }

    inputFile >> numStations >> timeBetweenStations;
    inputFile >> totalWBusCount >> totalMBusCount;
    inputFile >> wBusCapacity >> mBusCapacity;
    inputFile >> tripsBeforeCheckup >> checkupDurationWBus >> checkupDurationMBus;
    inputFile >> maxWaitingTime >> getOnOffTime;

    int numEvents;
    inputFile >> numEvents;

    for (int i = 0; i < numEvents; ++i) {
        char eventType;
        int ID2;
        string Pass_type, ARR_time, Start1, End1, extraInfo;

        inputFile >> eventType >> Pass_type >> ARR_time >> ID2 >> Start1 >> End1 >> extraInfo; 

        //Arrival / Leave Event
         Event* newEvent = nullptr;

        
        if (eventType == 'A') {
            newEvent = new ArrivalEvent(Pass_type, ARR_time, ID2, Start1, End1, extraInfo);
        } else if (eventType == 'L') {
            newEvent = new LeaveEvent(ARR_time, Start1);
        } else {
            cerr << "Unknown event type: " << eventType << endl;
            continue;
        }

        eventQueue.enqueue(newEvent);
       
    }

    inputFile.close();
}


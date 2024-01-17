#pragma once
#include "List.h"
#include "Passengers.h"
#include "Station.h"
#include "Time.h"
class Bus
{
    int limit;
    int currentStation = 0;
protected:
    std::string busType;
    int capacity;
    int journeys;
    int count;
    Time checkupTime;
    Time MovingTime;

public:

    List<Passengers> passengers;
    int numberOfTrips = 0; 
    Time busyTime;
    Time utilizationTime;
    Station* station = nullptr;
    int StationNum;
    int currentStation = 0;
    Bus(const std::string& type, int& cap, int& j,const Time& checkup);

    //setters
    void setBusType(const std::string& type);
    void setCapacity(int cap);
    void setJourneys(int j);
    void setCheckupTime(Time checkup);
    void setMovingTime(Time MovingTime);
    void setCurrentStation(int St);

    //getters
    std::string getBusType() const;
    int getCapacity() const;
    int getJourneys() const;
    Time getCheckupTime() const;
    Time getMovingTime() const;

    void GoForward();
    void GoBackward();

    bool needsCheckup() const;
    int getCurrentStation() const;

    void Remove_A_Pasenger(int passengerID) const;

};


class MBus : public Bus
{
public:
    MBus(const std::string& type, int& cap, int& j, const Time& checkup);

    void onboardPassenger(Passengers* Passenger);
    void offboardPassenger(Passengers* Passenger);
    void GoForward();
    void GoBackward();
    void Remove_A_Pasenger(int passengerID) const;
};


class WBus : public Bus
{
public:
 
    WBus(const std::string& type, int& cap, int& j, const Time& checkup);

    void onboardPassenger(Passengers* Passenger);
    void offboardPassenger(Passengers* Passenger);
    void GoForward();
    void GoBackward();
    void Remove_A_Pasenger(int passengerID) const;
};

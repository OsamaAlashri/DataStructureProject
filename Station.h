#pragma once
#include "LinkedList.h"
#include "Queue.h"
#include "PraiorityQueue.h"
#include "Passengers.h"

class Station
{
    LinkedList<Passengers*> waitingForwardNP;
    LinkedList<Passengers*> waitingBackwardNP;
    Queue<Passengers*> waitingForwardWP;
    Queue<Passengers*> waitingBackwardWP;
    Priority<Passengers*> waitingForwardSP;
    Priority<Passengers*> waitingBackwardSP;

public:
    bool WaitingPassengers();

    int stationNumber;



    Passengers* removeBackwardWP();
    Passengers* removeForwardWP();
    Passengers* removeBackwardSP();
    Passengers* removeForwardSP();
    Passengers* removeBackwardNP();
    Passengers* removeForwardNP();
    //New Phase2
    void IncreaseWaitingTimeNP(int time);

    void addPassenger(Passengers* passenger);

    void removePassenger(Passengers* passenger);

};
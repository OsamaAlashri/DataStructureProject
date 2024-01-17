#include "Station.h"
#include "Passengers.h"
bool Station::WaitingPassengers() {
    return waitingForwardNP.isEmpty() && waitingBackwardNP.isEmpty() &&
        waitingForwardSP.isEmpty() && waitingBackwardSP.isEmpty() &&
        waitingForwardWP.isEmpty() && waitingBackwardWP.isEmpty();
}
//New Phase2


void Station::IncreaseWaitingTimeNP(int time) {
    LinkedNode<Passengers*>* current = waitingForwardNP.getHead();
    while (current != nullptr) {
        current->data->IncreaseWaitingTime(time);
        if (current->data->getWaitingTime() > current->data->getMaxW()) {
            current->data->setType(PassengerType::Aged);
        }
        current = current->next;
    }

    current = waitingBackwardNP.getHead();
    while (current != nullptr) {
        current->data->IncreaseWaitingTime(time);
        if (current->data->getWaitingTime() > current->data->getMaxW()) {
            current->data->setType(PassengerType::Aged);
        }
        current = current->next;
    }
}



void Station::addPassenger(Passengers* passenger) {
    switch (passenger->getType()) {
    case PassengerType::NP:
        if (passenger->getEndStation() > this->stationNumber) {
            waitingForwardNP.append(passenger);
        }
        else {
            waitingBackwardNP.append(passenger);
        }
        break;
    case PassengerType::Aged:
    case PassengerType::POD:
    case PassengerType::Pregenant:
        if (passenger->getEndStation() > this->stationNumber) {
            waitingForwardSP.add(passenger);
        }
        else {
            waitingBackwardSP.add(passenger);
        }
        break;
    case PassengerType::WP:
        if (passenger->getEndStation() > this->stationNumber) {
            waitingForwardWP.enqueue(passenger);
        }
        else {
            waitingBackwardWP.enqueue(passenger);
        }
        break;
    }
}

void Station::removePassenger(Passengers* passenger) {
    switch (passenger->getType()) {
    case PassengerType::NP:
        if (!waitingForwardNP.isEmpty()) {
            waitingForwardNP.removeHead();
        }
        else if (!waitingBackwardNP.isEmpty()) {
            waitingBackwardNP.removeHead();
        }
        break;
    case PassengerType::Aged:
        if (!waitingForwardSP.isEmpty()) {
            return waitingForwardSP.removeFirst();
        }
        else if (!waitingBackwardSP.isEmpty()) {
            return waitingBackwardSP.removeFirst();
        }
        break;
    case PassengerType::POD:
        if (!waitingForwardSP.isEmpty()) {
            return waitingForwardSP.removeFirst();
        }
        else if (!waitingBackwardSP.isEmpty()) {
            return waitingBackwardSP.removeFirst();
        }
        break;
    case PassengerType::Pregenant:
        if (!waitingForwardSP.isEmpty()) {
            return waitingForwardSP.removeFirst();
        }
        else if (!waitingBackwardSP.isEmpty()) {
            return waitingBackwardSP.removeFirst();
        }
        break;
    case PassengerType::WP:
        if (!waitingForwardWP.isEmpty()) {
            waitingForwardWP.dequeue();
        }
        else if (!waitingBackwardWP.isEmpty()) {
            waitingBackwardWP.dequeue();
        }
        break;
    }
}


//End



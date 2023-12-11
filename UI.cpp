#include "UI.h"
#include <iostream>

void UI::startInteractiveMode(const List<Station>& stations) {
    for (int i = 0; i < stations.getSize(); ++i) {
        Station currentStation = stations.getElement(i);
        int currentTime = 0;  

        displayStationStatus(currentStation, currentTime);
        
        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();  // This line is to capture the Enter key press
    }
}

void UI::displayStationStatus(const Station& station, int time) {
    std::cout << "Time: " << time << std::endl;

    List<Passengers> waitingPassengers = station.getWaitingPassengers();
    std::cout << "Waiting Passengers:" << std::endl;
    for (int i = 0; i < waitingPassengers.getSize(); ++i) {
        Passengers passenger = waitingPassengers.getElement(i);
        std::cout << "Passenger ID: " << passenger.getID() << " Direction: " << passenger.getDirection() << std::endl;
    }

    List<Bus> availableBuses = station.getAvailableBuses();
    std::cout << "Available Buses:" << std::endl;
    for (int i = 0; i < availableBuses.getSize(); ++i) {
        Bus bus = availableBuses.getElement(i);
        std::cout << "Bus ID: " << bus.getID() << " Direction: " << bus.getDirection()
                  << " Type: " << bus.getType() << " Capacity: " << bus.getCapacity() << std::endl;

        List<Passengers> passengersOnBus = bus.getPassengers();
        std::cout << "Passengers on Bus:";
        for (int j = 0; j < passengersOnBus.getSize(); ++j) {
            std::cout << " " << passengersOnBus.getElement(j).getID();
        }
        std::cout << std::endl;
    }


    std::cout << "------------------------" << std::endl;
}

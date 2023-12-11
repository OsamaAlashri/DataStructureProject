#include "UI.h"
#include <iostream>

void UI::startInteractiveMode(const List<Station>& stations) {
    for (int i = 0; i < stations.getSize(); ++i) {
        Station currentStation = stations.getElement(i);
        int currentTime = 0;  // You can replace this with the actual time value

        // Display the status of the system at the current station and time
        displayStationStatus(currentStation, currentTime);

        // Wait for user input to proceed to the next station
        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();  // This line is to capture the Enter key press
    }
}

void UI::displayStationStatus(const Station& station, int time) {
    // Display the status of the system at a specific station and time
    std::cout << "Time: " << time << std::endl;

    // Display waiting passengers
    List<Passengers> waitingPassengers = station.getWaitingPassengers();
    std::cout << "Waiting Passengers:" << std::endl;
    for (int i = 0; i < waitingPassengers.getSize(); ++i) {
        Passengers passenger = waitingPassengers.getElement(i);
        std::cout << "Passenger ID: " << passenger.getID() << " Direction: " << passenger.getDirection() << std::endl;
    }

    // Display available buses
    List<Bus> availableBuses = station.getAvailableBuses();
    std::cout << "Available Buses:" << std::endl;
    for (int i = 0; i < availableBuses.getSize(); ++i) {
        Bus bus = availableBuses.getElement(i);
        std::cout << "Bus ID: " << bus.getID() << " Direction: " << bus.getDirection()
                  << " Type: " << bus.getType() << " Capacity: " << bus.getCapacity() << std::endl;

        // Display IDs of passengers on the bus
        List<Passengers> passengersOnBus = bus.getPassengers();
        std::cout << "Passengers on Bus:";
        for (int j = 0; j < passengersOnBus.getSize(); ++j) {
            std::cout << " " << passengersOnBus.getElement(j).getID();
        }
        std::cout << std::endl;
    }

    // Display other relevant information
    // ...

    std::cout << "------------------------" << std::endl;
}

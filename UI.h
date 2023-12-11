#pragma once
#include "Station.h"

class UI {
public:
    // Function to start the interactive mode
    static void startInteractiveMode(const List<Station>& stations);

    // Function to display the status of the system at a specific station and time
    static void displayStationStatus(const Station& station, int time);

    // Other input/output functions as needed
};

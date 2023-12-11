#pragma once
#include "Station.h"

class UI {
public:
    static void startInteractiveMode(const List<Station>& stations);
    static void displayStationStatus(const Station& station, int time);
};

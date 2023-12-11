#include "Bus.h"
#include "Time.h"

Bus::Bus() {
    // Initialize default values here, if needed.
}

Bus::Bus(const std::string & type, int& cap, int& j, const Time & checkup)
    : busType(type), capacity(cap), journeys(j), checkupTime(checkup) {}

void Bus::setBusType(const std::string & type) { busType = type; }
void Bus::setCapacity(int cap) { capacity = cap; }
void Bus::setJourneys(int j) { journeys = j; }
void Bus::setCheckupTime(Time checkup) { checkupTime = checkup; }

std::string Bus::getBusType() const { return busType; }
int Bus::getCapacity() const { return capacity; }
int Bus::getJourneys() const { return journeys; }
Time Bus::getCheckupTime() const { return checkupTime; }

bool Bus::needsCheckup() const { return journeys >= limit; } //limit variable for journeys need to be added. If succeeds limit, then checkUp.

}

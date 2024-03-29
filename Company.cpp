
#include "Company.h"


Company::Company()
{
	gettingTime = -1;
	stations = nullptr;
	timeBetweenStations = maxWaitingTime = -1;
	journeysBeforeCheckup = wBusCheckupPeriod = mBusCheckupPeriod = -1;
	promotedPassengers = numberOfStations = 0;
	boardingTime = -1;
}

Event* Company::createArrivalEvent(ifstream& file)
{

	int hour, minute, id, startStation, endStation, priority = -1;
	char colon;
	file >> passengerType >> hour >> colon >> minute >> id >> startStation >> endStation;

	if (passengerType == "SP") 
	{
		file >> type;
		if (type == "aged")
			priority = 2;
		else if (type == "POD")
			priority = 1;
		else
			priority = 0;
	}
	time.setTime(hour,minute,0);

	return new ArrivalEvent(time, id, passengerType, startStation, endStation, priority);
}

Event* Company::createLeaveEvent(ifstream& file)
{
	int hour, minute, id;
	char colon;

	file >> hour >> colon >> minute >> id;

	return new LeaveEvent(time, id);

}



void Company::generateOutputFile()
{
	ofstream file("output.txt");
	file << "ID\t\t\tFT\t\t\tAT\t\t\tWT\t\t\tTT\n";
	int npCount = 0,
		spCount = 0,
		wpCount = 0;
	int totalWaitingTime = 0;
	while (!finishedPassengers.isEmpty()) {
		Passengers* passenger = finishedPassengers.dequeue();

		file << passenger->getID() << "\t\t\t";
		file << passenger->getArrivalTime().geTime();
	

		totalWaitingTime += passenger->getGetOnOff().geTime();

		string type = passenger->getPassengerType();

		if (type == "NP")
			npCount++;
		else if (type == "SP")
			spCount++;
		else
			wpCount++;
	}
	float totalPAssengersCount = npCount + spCount + wpCount;
	file << "Passengers: " << totalPAssengersCount << "   [NP: " << npCount << ", SP: " << spCount << ", WP: " << wpCount << "]\n";
	file << "passenger Avg Wait time= " << (totalWaitingTime / totalPAssengersCount) << "\n";
	file << "Auto-promoted passengers: " << (float)promotedPassengers / totalPAssengersCount * 100.0 << "%\n";
}


void Company::startSimulation() 
{
	/*Starts a simulation and displays it in the UI class*/
}


void Company::OPENFILE(const string& filename)
{
	ifstream inputFile(filename);

		if (!inputFile.is_open()) {
			cerr << "Error opening input file: " << filename << endl;
			return;
		}

	inputFile >> numStations >> timeBetweenStations;
	inputFile >> totalWBusCount >> totalMBusCount;
	inputFile >> wBusCapacity >> mBusCapacity;
	inputFile >> tripsBeforeCheckup >> checkupDurationWBus >> checkupDurationMBus;
	inputFile >> maxWaitingTime >> getOnOffTime >> timestep;

	int numEvents;

	inputFile >> numEvents;
	for (int i = 0; i < numEvents; ++i) 
{
		
		int eventTime;
		int id;
		string passenegerType;
		int startStation;
		int endStation;
		int priority;

		inputFile >> eventType >> eventTime >> id >> passenegerType >> startStation >> endStation >> priority;

		//Arrival or Leave Event A for arrival and L for Leave event
		Event* newEvent = NULL;



		if (eventType == 'A') {
			newEvent = new ArrivalEvent(time, id ,passenegerType, startStation, endStation, priority);
		}
		else if (eventType == 'L') {
			newEvent = new LeaveEvent (time, id);
		}
		else {
			cerr << "Unknown event type: " << eventType << endl;
			continue;
		}

		events.enqueue(newEvent);
	}
}

void Company::releasebus()
{
	if (time.getHour() < 4 ) 
	{ 
		return;
	}

	Bus* bus = stationZero.dequeue();
	bus->setMovingTime(time);
	movingBuses.enqueue(bus); // add to moving buses list 
	
}

void Company::releaseFromCheckup(Queue<Bus*>& checkupBuses, Time checkupTime, Time timenow)
{
	while (!checkupBuses.isEmpty()) 
	{
		Bus* bus = checkupBuses.dequeue();
		movingBuses.enqueue(bus);
	}
}

void Company::addToCheckup(Bus* bus, Time timenow)
{
	bus->setCheckupTime(timenow); //maintancetime is now 
	if (bus->getBusType() == "Mixed") {
		checkupMixedBuses.enqueue(bus);
	}
	else {
		checkupWheelBuses.enqueue(bus);
	}
}

void Company::RemovePassenger(Bus* bus, Passengers* passengers) {
	int DesiredStation = passengers->getEndStation();

	if (bus->getCurrentStation() == DesiredStation) 
	{
	bus->Remove_A_Pasenger(passengers->getID());
	}
}


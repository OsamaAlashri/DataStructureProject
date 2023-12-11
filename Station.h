
#include "Queue.h"
#include "List.h"
#include "Passengers.h"
#include <iostream>

class Station {
	int stationNumber;
	int maxStations;
public:

	List<Passengers> Np; //normal person cal leave the queue after MaxW time (list is needed not queue)
	Queue<Passengers> Aged;
	Queue<Passengers> POD;
	Queue<Passengers> PW;
	Queue<Passengers> Wp;
	bool CheckTime(); //checks if in working hours


};

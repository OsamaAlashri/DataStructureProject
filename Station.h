
#include "Queue.h"
#include "List.h"
#include "Passengers.h"
#include <iostream>
using namespace std;

class Station {
public:
	int stationNumber;
	List<Passengers> Np; //normal person cal leave the queue after MaxW time (list is needed not queue)
	Queue<Passengers> Aged;
	Queue<Passengers> POD;
	Queue<Passengers> PW;
	Queue<Passengers> Wp;



};
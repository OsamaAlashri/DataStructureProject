#pragma once
#include <fstream>
#include <string>
#include "passenger.h"
using namespace std;
class OutputFileProcessor
{
public:
    OutputFileProcessor();
    ~OutputFileProcessor();
    void openFile(string filename);
    void closeFile();
    void writeLine(string line);
    static void writeLineStatic(string line);
    void addFinishedPassenger(int current_minute, Passenger *passenger);
    void printHeader();
    static void increment_passenger_count(PassengerType passenger_type);
    static void incrementAutoPromotedPassengerCount();
    static void printSummary();
    static void printTotalPassengers();
    static void printAverageWaitTime();
    static void printPromotedPassengersPercentage();
    static void printTotalBuses();
    static void printAverageTripTime();

private:
    static ofstream outputFile;
    static bool is_header_printed;
    static int total_wait_time_in_minutes;
    static int total_trip_time_in_minutes;

public:
    static int total_normal_passengers;
    static int total_special_passengers;
    static int total_wheel_passengers;
    static int total_pormoted_passengers;
    static int number_of_MBuses;
    static int number_of_WBuses;
};
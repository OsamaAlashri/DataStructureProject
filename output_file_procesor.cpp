#include "output_file_processor.h"
OutputFileProcessor::OutputFileProcessor()
{
    // Create a new file
    outputFile.open("output.txt", std::ios_base::app);
    printHeader();
}
ofstream OutputFileProcessor::outputFile;
void OutputFileProcessor::writeLine(string line)
{
    outputFile << line << endl;
}

int OutputFileProcessor::total_normal_passengers = 0;
int OutputFileProcessor::total_special_passengers = 0;
int OutputFileProcessor::total_wheel_passengers = 0;
int OutputFileProcessor::total_pormoted_passengers = 0;
bool OutputFileProcessor::is_header_printed = false;
int OutputFileProcessor::total_wait_time_in_minutes = 0;
int OutputFileProcessor::number_of_MBuses = 0;
int OutputFileProcessor::number_of_WBuses = 0;
int OutputFileProcessor::total_trip_time_in_minutes = 0;
void OutputFileProcessor::increment_passenger_count(PassengerType passenger_type)
{
    if (passenger_type == PassengerType::NP)
    {
        total_normal_passengers++;
    }
    else if (passenger_type == PassengerType::WP)
    {
        total_wheel_passengers++;
    }
    else
    {
        total_special_passengers++;
    }
}
void OutputFileProcessor::addFinishedPassenger(int current_minute, Passenger *passenger)
{
    // from the minutes calculate current hour and minute
    increment_passenger_count(passenger->getType());
    int current_hour = current_minute / 60;
    int current_minute_of_hour = current_minute % 60;
    // calculate trip time in minutes
    int trip_time_in_minutes = 0;
    // write TT as hours:minutes
    int trip_time_in_hours = trip_time_in_minutes / 60;
    int trip_time_in_minutes_of_hour = trip_time_in_minutes % 60;
    string TT = to_string(trip_time_in_hours) + ":" + to_string(trip_time_in_minutes_of_hour);
    string FT = to_string(current_hour) + ":" + to_string(current_minute_of_hour);
    string ID = to_string(passenger->getId());
    string AT = passenger->getArrivalTime();
    int arrival_time_in_minutes = passenger->getArrivalTimeInMinutes();
    int wait_time = current_minute - arrival_time_in_minutes;
    total_wait_time_in_minutes += wait_time;
    string WT = to_string(wait_time);
    string line = FT + "    " + ID + "  " + AT + "  " + WT + "  " + TT;
    writeLine(line);
}

void OutputFileProcessor::printHeader()
{
    if (!is_header_printed)
    {
        string space_between_headers = "    ";
        outputFile
            << "Note: TT is yet to be calculated\n"
            << "FT" + space_between_headers + "ID" + space_between_headers + "AT" + space_between_headers + "WT" + space_between_headers + "TT"
            << endl;
        is_header_printed = true;
    }
}
OutputFileProcessor::~OutputFileProcessor()
{
    outputFile.close();
}
void OutputFileProcessor::printTotalPassengers()
{
    string line_to_print = "Total Passengers: ";
    line_to_print += to_string(total_normal_passengers + total_special_passengers + total_wheel_passengers);
    line_to_print += " [NP: ";
    line_to_print += to_string(total_normal_passengers);
    line_to_print += ", SP: ";
    line_to_print += to_string(total_special_passengers);
    line_to_print += ", WP: ";
    line_to_print += to_string(total_wheel_passengers);
    line_to_print += "]";
    writeLineStatic(line_to_print);
}
void OutputFileProcessor::incrementAutoPromotedPassengerCount()
{
    total_pormoted_passengers++;
}
void OutputFileProcessor::printPromotedPassengersPercentage()
{
    string line_to_print = "Promoted Passengers Percentage: ";
    line_to_print += to_string((total_pormoted_passengers * 100) / (total_normal_passengers + total_special_passengers + total_wheel_passengers));
    line_to_print += "%";
    writeLineStatic(line_to_print);
}
void OutputFileProcessor::writeLineStatic(string line)
{
    outputFile.open("output.txt", std::ios_base::app);
    outputFile << line << endl;
    outputFile.close();
}

void OutputFileProcessor::printAverageWaitTime()
{
    string line_to_print = "Average Wait Time= 0:";
    line_to_print += to_string(total_wait_time_in_minutes / (total_normal_passengers + total_special_passengers + total_wheel_passengers));
    writeLineStatic(line_to_print);
}
void OutputFileProcessor::printTotalBuses()
{
    string line_to_print = "Total Buses: ";
    line_to_print += to_string(number_of_MBuses + number_of_WBuses);
    line_to_print += " [MBus: ";
    line_to_print += to_string(number_of_MBuses);
    line_to_print += ", WBus: ";
    line_to_print += to_string(number_of_WBuses);
    line_to_print += "]";
    writeLineStatic(line_to_print);
}
void OutputFileProcessor::printAverageTripTime()
{
    string line_to_print = "Average Trip Time= 0:";
    line_to_print += to_string(total_trip_time_in_minutes / (total_normal_passengers + total_special_passengers + total_wheel_passengers));
    writeLineStatic(line_to_print);
}
void OutputFileProcessor::printSummary()
{
    printTotalPassengers();
    printAverageWaitTime();
    printAverageTripTime();
    printPromotedPassengersPercentage();
    printTotalBuses();
}
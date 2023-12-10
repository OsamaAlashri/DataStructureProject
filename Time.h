#include <iostream>
#include <iomanip>
using namespace std;

class Time {
    int hour;
    int minute;

public:
    Time() : hour(0), minute(0) {}

    void setTime(int h, int m) {
        hour = (h >= 0 && h < 24);
        minute = (m >= 0 && m < 60);
    }

    void printTime() {
        cout << setfill('0') << setw(2) << hour << ":"
            << setfill('0') << setw(2) << minute << endl;       //output formatting in a (00:00) format.
    }

    void tick() {
        ++minute;
        if (minute >= 60) {
            minute = 0;
            ++hour;
            if (hour >= 24) {
                hour = 0;
            }
        }
    }
};
/* Event.h -  Event Class
    Name: Liam Walker
    Module: 6
    Project: 3
    Problem Statement: 
    Plan:
    1. Follow lab instructions to learn more about overiding the copy constructor and assignment operator

*/
#ifndef EVENT_H
#define EVENT_H


#include <cstring>
#include <iostream>
#include "TimeDate.h"
using namespace std;

class Event {
    private :
        TimeDate start_time, end_time;  // start and end timestamps
        string description; // event summary text
        
    public:
        // initialize start/end TimeDate and description
        Event(int start_hour, int start_minute, int start_day, 
            string start_month, 
            int end_hour, int end_minute, int end_day,
            string end_month, string description) : 
                start_time(start_hour, start_minute, start_day, start_month),
                end_time(end_hour, end_minute, end_day, end_month),
                description(description)
        { };
        // combine details into one readable phrase
        string getEvent() {
            return description + " starts at " + 
                start_time.getTimeDate() +
                ", ends at " +
                end_time.getTimeDate();
        }
        ~Event() {
            cout << "In destructor for: " << description << endl;  // cleanup trace
        }

};


#endif
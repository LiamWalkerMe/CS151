/* TimeDate.h -  TimeDate Class
    Name: Liam Walker
    Module: 6
    Project: 3
    Problem Statement: 
    Plan:
    1. Follow lab instructions to learn more about overiding the copy constructor and assignment operator

*/
#ifndef TIMEDATE_H
#define TIMEDATE_H

#include <cstring>
#include <iostream>
using namespace std;


class TimeDate {
    private: 
        int hour, minute, day;  // store time and day values
        string month; // store month name
    public:
        // constructor initializes all fields with values passed in
        TimeDate(int hour, int minute, int day, string month) :  
            hour(hour), minute(minute), day(day), month(month)
        { }
        string getTimeDate(); // format a readable time/date string
        ~TimeDate(); // destructor with debug output

};

string TimeDate::getTimeDate() { 
    string print_hour = to_string(hour); 
    string am_pm = (hour < 12 ? "am" : "pm"); // decide am/pm
    if (hour == 0)
        print_hour = "12"; // midnight hour display fix
    else if (hour > 12) 
        print_hour = to_string(hour - 12); // convert to 12-hour format
    return month + " " + to_string(day) +  
            " at " + print_hour + ":" +   
            (minute < 10 ? "0" : "") + to_string(minute) + am_pm;  
} 

TimeDate::~TimeDate() {
    cout << "In destructor for: " << getTimeDate() << endl; // log destruction
} 

#endif
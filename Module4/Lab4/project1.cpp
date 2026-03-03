/* project1.cpp - Manipulate a time variable and corresponding structure, print today's 
                  date and time in various formats, and determine how to adjust the internal form of other 
                  dates

    Name: Liam Walker
    Module: 4
    Project: 1
    Problem Statement: Need to learn about ctime.

    Algorithm / Plan:
    1. Follow lab instructions to learn about ctime

*/
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {

    // Set timezone to Pacific Time
    #ifdef _WIN32
        putenv("TZ=PST8PDT");        // Windows  
    #else
        setenv("TZ", "PST8PDT", 1);  // Unix/Linux...  
    #endif
    tzset();

    // Define Days and Months
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    //Initialize time
    time_t now = time(nullptr);
    tm *local = localtime(&now);

    //Output time using Tm format
    cout << "Today's date in various formats:" << endl;
    cout << left << setw(16) << "Format:" << setw(5) << "" << setw(10) << "Today:" << endl;

    cout << setw(16) << "m/d/yy:" << setw(5) << "";

    cout << local->tm_mon + 1 << "/" 
        << local->tm_mday << "/" 
        << local->tm_year - 100 << endl;

    cout << setw(16) << "January 1, 2000:" << setw(5) << "";

    cout << months[local->tm_mon] << " " 
        << local->tm_mday << ", " 
        << local->tm_year + 1900 << endl;

    cout << setw(16) << "d-mmm-year:" << setw(5) << "";

    cout  << local->tm_mday << "-"  
        << months[local->tm_mon].substr(0, 3) << "-" 
        << local->tm_year + 1900 << endl << endl;


    struct tm *timeinfo = localtime(&now);

    char buffer[80];

    // Output time in Strftime format
    cout << " Same information using the strftime function:" << endl;
    cout << left << setw(16) << "Format:" << setw(5) << "" << setw(10) << "Today:" << endl;

    cout << setw(16) << "m/d/yy:" << setw(5) << "";

    strftime(buffer, 80, "%m/%d/%y", timeinfo);
    cout << buffer << endl;

    cout << setw(16) << "January 1, 2000:" << setw(5) << "";

    strftime(buffer, 80, "%B %d, %Y", timeinfo);
    cout << buffer << endl;

    cout << setw(16) << "d-mmm-year:" << setw(5) << "";

    strftime(buffer, 80, "%d-%b-%Y", timeinfo);
    cout << buffer << endl << endl;


    cout << "The current time in two formats: " << endl;

    strftime(buffer, 80, "%-I:%M %p", timeinfo);
    cout << setw(13) << buffer << "<12-hours>" << endl;


    strftime(buffer, 80, "%H:%M", timeinfo);
    cout << setw(13) << buffer << "<24-hours>" << endl;


    //Calculate big event using tm format
    cout << "Event:" << endl;
    //Big event! My Birthday
    tm event;  
    event.tm_year = 2006 - 1900;  // current year  
    event.tm_mon = 6;      // month (1 - 12)  
    event.tm_mday = 9;     // day (1 - 31) 
    event.tm_hour = 3;     // hour (0 - 23) 
    event.tm_min = 40;      // minute (0 - 59)  
    event.tm_sec = 0;      // second (0 - 59) 
    event.tm_isdst = 1;    // daylight savings (true/false) 

    time_t time_of_event = mktime(&event);  
    cout << "The big event occurred on "  
         << ctime(&time_of_event) << "and occurred " << time_of_event 
         << " seconds after epoch!" << endl;



    int seconds_in_a_week = 7 * 24 * 60 * 60;
    cout << "There are " << seconds_in_a_week << " seconds in a week" << endl;
    

    time_t one_week_prior = time_of_event - 604800;

    cout << "One week before the event was: " << ctime(&one_week_prior);

    mktime(&event);
    strftime(buffer, 80, "Day of Week: %A, Day of Year: %j", &event);

    // Output using the strftime buffer
   cout << "Using strftime: " << buffer << endl;




    return 0;
}
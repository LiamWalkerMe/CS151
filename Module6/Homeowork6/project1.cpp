/* project1.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 6
    Project: 1
    Problem Statement:

    Algorithm / Plan:
    1. Gather the date number from the user, or the date
    2. Convert it to the opposite type ex: date -> number, number-> date
    3. Impliment operator overloading for ++ << --
    4. These should increase, decrease or convert the date

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include "numOfYear.h"
using namespace std;

int main() {
    //Demonstrate the Number to Date Function
    cout << "Number -> to Date" << endl;
    numOfYear day(15);
    cout << "Day 15: " << day << endl;
    day.setNum(31);
    cout << "Day 31: " << day << endl;
    day.setNum(59);
    cout << "Day 59: " << day << endl;
    day.setNum(180);
    cout << "Day 180: " << day << endl;
    day.setNum(360);
    cout << "Day 360: " << day << endl;
    cout << endl;

    //Showcase the Date to Number
    cout << "Date -> to Number" << endl;
    numOfYear day2("January", 1);
    cout << day2 << " (Day " << day2.getDayOfYear() << ")" << endl;
    numOfYear day3("March", 4);
    cout << day3 << " (Day " << day3.getDayOfYear() << ")" << endl;
    numOfYear day4("July", 25);
    cout << day4 << " (Day " << day4.getDayOfYear() << ")" << endl;
    numOfYear day5("December", 31);
    cout << day5 << " (Day " << day5.getDayOfYear() << ")" << endl;
    cout << endl;

    // Showcase prefix and postfix ++ and -- operators

    numOfYear test(100);

    cout << "Operator Showcase:" << endl;

    cout << "Preincrement" << endl;
    cout << "Original date: " << test << endl;
    cout << "During ++date " << ++test << endl;
    cout << "After ++date " << test << endl << endl;

    cout << "Predecrement" << endl;
    cout << "Original date: " << test << endl;
    cout << "During --date " << --test << endl;
    cout << "After --date " << test << endl << endl;

    cout << "Postincrement" << endl;
    cout << "Original date: " << test << endl;
    cout << "During date++ " << test++ << endl;
    cout << "After date++ " << test << endl << endl;

    cout << "Postdecrement" << endl;
    cout << "Original date: " << test << endl;
    cout << "During date-- " << test-- << endl;
    cout << "After date-- " << test << endl << endl;


    // Test wrap-around
    numOfYear endYear(365);
    cout << "End of year: " << endYear << endl;
    cout << "++ endYear: " << ++endYear << " (Day " << endYear.getDayOfYear() << ")" << endl;

    numOfYear startYear(1);
    cout << "Start of year: " << startYear << endl;
    cout << "-- startYear: " << --startYear << " (Day " << startYear.getDayOfYear() << ")" << endl;

    // Test invalid input
    numOfYear invalidDay(400); // Should default to 1
    cout << "Invalid day (400): " << invalidDay << " (Day " << invalidDay.getDayOfYear() << ")" << endl;
    numOfYear invalidDate("NotAMonth", 10); // Should exit with error


    return 0;
}
/* project2.cpp -  Copy Constructors
    Name: Liam Walker
    Module: 6
    Project: 1
    Problem Statement: 
    Plan:
    1. Follow lab instructions to learn more about classes

*/
#ifndef NUMOFYEAR_H
#define NUMOFYEAR_H

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class numOfYear {
private:
    int num;
    static const string months [12];
    static const string days [7];
    static const int daysineachmonth [12];

public:
    numOfYear(int input);       // constructor
    numOfYear(string month, int day); // constructor with month and day
    int getDayOfYear();              // getter function
    int setNum(int input);
    friend ostream& operator<<(ostream &, const numOfYear &); // friend function for output stream
    numOfYear& operator--(); // prefix decrement
    numOfYear& operator++(); // prefix increment
    numOfYear operator--(int); // postfix decrement
    numOfYear operator++(int); // postfix increment
};

//Define Constants
const string numOfYear::months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const string numOfYear::days[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
const int numOfYear::daysineachmonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//Number to Date constructor
numOfYear::numOfYear(int input) {
    if (input >= 1 && input <= 365) {
        num = input;
    } else {
        num = 1; // default
    }
}
//Setter
int numOfYear::setNum(int input) {
    if (input >= 1 && input <= 365) {
        this->num = input;
    } else {
        this->num = 1; // default
    }
    return num;
}

//Date to Number constructor
numOfYear::numOfYear(string month, int day) {
    int monthIndex = -1;
    for (int i = 0; i < 12; i++) {
        if (months[i] == month) {
            monthIndex = i;
            break;
        }
    }
    if (monthIndex != -1 && day > 0 && day <= daysineachmonth[monthIndex]) {
        this->num = 0;
        for (int i = 0; i < monthIndex; i++) {
            this->num += daysineachmonth[i];
        }
        this->num += day;
    } else {
        cerr << "Invalid month name or day out of range for the month." << endl;
        exit(1);
    }
}
//Getter
int numOfYear::getDayOfYear() {
    return num;
}

//<< Operator
ostream& operator<<(ostream &out, const numOfYear &date) {
    int dayOfYear = date.num;
    int monthIndex = 0;
    while (dayOfYear > numOfYear::daysineachmonth[monthIndex]) {
        dayOfYear -= numOfYear::daysineachmonth[monthIndex];
        monthIndex++;
    }
    out << numOfYear::months[monthIndex] << " " << dayOfYear;
    return out;
}

// -- Operator
numOfYear& numOfYear::operator--() {
    if (num > 1) {
        num--;
    } else {
        num = 365;
    }
    return *this;
}

// ++ Operator
numOfYear& numOfYear::operator++() {
    if (num < 365) {
        num++;
    } else {
        num = 1;
    }
    return *this;
}

// 
numOfYear numOfYear::operator--(int) {
    numOfYear temp = *this;
    --(*this);
    return temp;
}

numOfYear numOfYear::operator++(int) {
    numOfYear temp = *this;
    ++(*this);
    return temp;
}

#endif

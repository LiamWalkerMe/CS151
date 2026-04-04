/* project2.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 6
    Project: 2
    Problem Statement:

    Algorithm / Plan:
    1. Test the Money class by creating several instances of it and demonstrating the copy constructor, move constructor and assignment operator.

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include "Money.cpp"
using namespace std;

// declare helper to force move construction path
Money testMove(Money);

int main() {

    // construct Money objects from strings
    Money money1("4.90");
    Money money2("1.27");
    Money money3("3.24");
    Money money4("1.99");

    // add and print results
    Money money5 = money1 + money2;
    cout << money1 << " + " << money2 << " = " << money5 << endl;

    Money money6 = money3 + money4;
    cout << money3 << " + " << money4 << " = " << money6 << endl;

    // compare and print the bigger value
    if (money5 >= money6) {
        cout << "The larger value is: " << money5 << endl;
    } else {
        cout << "The larger value is: " << money6 << endl;
    }

    // assign a new temporary Money
    money1 = Money("5.00");

    // assign sum again
    money5 = money1 + money2;
    cout << money1 << " + " << money2 << " = " << money5 << endl;

    if (money5 >= money6) {
        cout << "The larger value is: " << money5 << endl;
    } else {
        cout << "The larger value is: " << money6 << endl;
    }

    // invoke testMove to test move semantics path
    Money returned = testMove(Money("8.36")); 
    cout << "Returned: " << returned << endl;

    return 0;
}

// Test the move constructor  
Money testMove(Money in) {
    return in;
}  
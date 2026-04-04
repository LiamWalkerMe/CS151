/* project.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 
    Project: 
    Problem Statement:

    Algorithm / Plan:
    1.


*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include "Event.h"
#include "TimeDate.h"
using namespace std;

int main() {
    
    Event party(17, 30, 14, "Oct.", 20, 30, 14, "Oct.", 
        "My Birthday Party") ;
    cout << party.getEvent() << endl ;

    Event christmas(00, 00, 25, "Dec.", 23, 59, 25, "Dec.", 
        "Christmas Party") ;
    cout << christmas.getEvent() << endl ;
    return 0;
}
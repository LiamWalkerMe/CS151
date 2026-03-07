/* project1.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 5
    Project: 1
    Problem Statement:

    Algorithm / Plan:
    1. Declare constant string tables for 0–19 (kUnder20), the tens (kTens),
       "Hundred" (kHundred) and the thousand units (kThousands).
    2. Constructor takes an int, checks it’s in range, and stores it in a private
       member.
    3. print() first handles zero, then adds a thousands word if needed.
    4. print() adds a hundreds word if needed.
    5. print() uses the tens and under‑20 tables for the remaining part.
    6. print() writes the accumulated words to cout; out‑of‑range values were
       reported by the constructor.

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>

#include "numbers.h"
using namespace std;

int main() {

    int number = 0;

    do {
        cout << "Enter a number between 0 and 9999 (enter -1 to quit): ";
        cin >> number;
        Numbers num(number);
        num.print();
        cout << endl;
    } while (number != -1);
    
    


    return 0;
}
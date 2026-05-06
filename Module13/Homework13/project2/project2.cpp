/* project.cpp - Test SimpleVector class with push, pop, and exception handling
    Name: Liam Walker
    Module: 
    Project: 
    Problem Statement: Test SimpleVector with integers and strings, demonstrating push/pop and exception handling

    Algorithm / Plan:
    1. Create SimpleVector of ints with capacity of 5
    2. Push 6 numbers (6th should throw exception)
    3. Pop until exception (empty vector)
    4. Create SimpleVector of strings with capacity of 5
    5. Push 6 strings (6th should throw exception)
    6. Pop until exception (empty vector)
    7. Display descriptive messages for each operation

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include <string>

#include "SimpleVector.h"
using namespace std;



int main() {

    // Test SimpleVector with integers and strings, demonstrating push/pop and exception handling
    cout << "========== Testing SimpleVector with Integers ==========" << endl;
    cout << "Creating a SimpleVector of integers with capacity 5..." << endl;
    SimpleVector<int> intVector(5);

    cout << "\nAttempting to push 6 different numbers..." << endl;
    int numbers[] = {10, 20, 30, 40, 50, 60};
    for (int i = 0; i < 6; i++) {
        try {
            cout << "Pushing " << numbers[i] << "...";
            intVector.push_back(numbers[i]);
            cout << " Success!" << endl;
        } catch (const overflow_error& e) {
            cout << " EXCEPTION: " << e.what() << endl;
        }
    }
    // Pop until exception, but the vector is empty
    cout << "\nPopping integers until exception is thrown..." << endl;
    while (true) {
        try {
            int value = intVector.pop_back();
            cout << "Popped: " << value << endl;
        } catch (const underflow_error& e) {
            cout << "EXCEPTION: " << e.what() << endl;
            break;
        }
    }

    cout << "\n========== Testing SimpleVector with Strings ==========" << endl;
    cout << "Creating a SimpleVector of strings with capacity 5..." << endl;
    SimpleVector<string> stringVector(5);

    // Push 6 strings, 6th should throw exception
    cout << "\nAttempting to push 6 different strings..." << endl;
    string strings[] = {"apple", "banana", "cherry", "date", "elderberry", "fig"};
    for (int i = 0; i < 6; i++) {
        try {
            cout << "Pushing \"" << strings[i] << "\"...";
            stringVector.push_back(strings[i]);
            cout << " Success!" << endl;
        } catch (const overflow_error& e) {
            cout << " EXCEPTION: " << e.what() << endl;
        }
    }
    // Pop until exception but the vector is empty
    cout << "\nPopping strings until exception is thrown..." << endl;
    while (true) {
        try {
            string value = stringVector.pop_back();
            cout << "Popped: \"" << value << "\"" << endl;
        } catch (const underflow_error& e) {
            cout << "EXCEPTION: " << e.what() << endl;
            break;
        }
    }

    cout << "\n========== Test Complete ==========" << endl;

    return 0;
}
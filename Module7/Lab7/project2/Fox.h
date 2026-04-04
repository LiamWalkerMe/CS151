/* Fox.h - Inherited class from Animal
    Name: Liam Walker
    Module: 7
    Project: 2
    Problem Statement: create three classes, Animal, Owl, Fox and a  main  function, each in a separate file

    Algorithm / Plan:
    1. Create instances of Animal, Fox, and Owl classes
    2. Call showInfo() on each instance
    3. Call makeNoise() on each instance
    4. Call sleep() on each instance


*/
#ifndef FOX_H
#define FOX_H

using namespace std;

#include "Animal.h"

class Fox : public Animal {
public:
    // Constructor
    Fox(const string& name) : Animal(name) {
        cout << "A Fox " << getName() << " has been created." << endl;
    }
    // Override makeNoise and showInfo
    void makeNoise() const override {
        cout << "The Fox " << getName() << " is yelping." << endl;
    }

    void showInfo() const override {
        cout << "The Fox " << getName() << endl;
    }
};

#endif

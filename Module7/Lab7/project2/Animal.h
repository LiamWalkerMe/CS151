/* Animal.h - Base class for all animals
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
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
    string name;

public:
    // Constructor
    Animal(const string& name) : name(name) {
        cout << "An Animal " << this->name << " has been created." << endl;
    }
    // Getter and Setter for name
    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    // Virtual functions for polymorphism
    void sleep() const {
        cout << "The Animal " << name << " is sleeping." << endl;
    }

    virtual void makeNoise() const {
        cout << "The Animal " << name << " is making a noise." << endl;
    }

    virtual void showInfo() const {
        cout << "The Animal " << name << endl;
    }
};

#endif

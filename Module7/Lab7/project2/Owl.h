/* Owl.h - Inherited class from Animal
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
#ifndef OWL_H
#define OWL_H

using namespace std;

#include "Animal.h"

class Owl : public Animal {
private:
    string breed;

public:
    // Constructor
    Owl(const string& name, const string& breed)
        : Animal(name), breed(breed) {
        cout << "An Owl " << getName() << " of breed " << this->breed
                  << " has been created." << endl;
    }

    // Getter and Setter for breed
    string getBreed() const { return breed; }
    void setBreed(const string& breed) { this->breed = breed; }

    // Override makeNoise and showInfo
    void makeNoise() const override {
        cout << "The Owl " << getName() << " is hooting." << endl;
    }

    void showInfo() const override {
        cout << "The Owl " << getName() << " of breed " << breed << "."
                  << endl;
    }
};

#endif

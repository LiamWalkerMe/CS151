/* project2.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 7
    Project: 2
    Problem Statement: create three classes, Animal, Owl, Fox and a  main  function, each in a separate file

    Questions:
    1. What is/are the names of the base classes? 
        Animal
    2. What is/are the names of the derived classes? 
        Owl, Fox
    3. Does  Animal  have a parent class? 
        No
    4. Is the function  showInfo  overridden?  Is  makeNoise?  Is  sleep? 
        No, only showInfo and makeNoise are overridden.
    5. If the data member  name  in the  Animal  class were made  protected  (instead of  private),  would you need to use getters in the  showInfo  function of the child classes  Fox  and  Owl? 
        No, if the data member name were made protected, the child classes would have direct access to it and would not need to use getters in the showInfo function.
    6. What if the class data members were left  private,  but the base access modifiers to the  Animal  class in both child classes were made  protected, would you need to use getters in the  showInfo  function of the child classes  Fox  and  Owl?
        Yes, if the class data members were left private, the child classes would still need to use getters to access the name data member in the showInfo function, even if the base access modifiers were made protected.

    Algorithm / Plan:
    1. Create instances of Animal, Fox, and Owl classes
    2. Call showInfo() on each instance
    3. Call makeNoise() on each instance
    4. Call sleep() on each instance


*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include "Animal.h"
#include "Fox.h"
#include "Owl.h"
using namespace std;

int main() {
    // Create instances of Animal, Fox, and Owl classes
    Animal oscar("Oscar");
    Owl errol("Errol", "Great Grey");
    Fox foxy("Foxy");

    // Call showInfo() on each instance
    oscar.showInfo();
    errol.showInfo();
    foxy.showInfo();

    // Call makeNoise() on each instance
    oscar.makeNoise();
    errol.makeNoise();
    foxy.makeNoise();

    // Call sleep() on each instance
    oscar.sleep();
    errol.sleep();
    foxy.sleep();

    return 0;
}

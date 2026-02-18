/* Planet.cpp - planet class to store name, diameter, and distance
Author: Liam Walker 
Module: 1
Project: Homework 1
*/

#include <iostream>
#include "Planet.h"

using namespace std;

string Planet::getName() {
    return name;
}

int Planet::getDiameter() {
    return diameter;
}

long long Planet::getDistance() {
    return distance;
}

Planet::Planet(string initial_name, int initial_diameter, long long initial_distance) {
    name = initial_name;
    diameter = initial_diameter;
    distance = initial_distance;
}

Planet::Planet() {

}
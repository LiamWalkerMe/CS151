/* Planet.cpp - planet class to store name, diameter, and distance
Author: Liam Walker 
Module: 1
Project: Homework 1
*/
#ifndef PLANET_H
#define PLANET_H
#include <iostream>
using namespace std;

class Planet {
    private:
        string name;
        int diameter;
        long long distance;
    public:
        string getName();
        int getDiameter();
        long long getDistance();

        Planet(string initial_name, int initial_diameter, long long initial_distance);
        Planet();
};
#endif
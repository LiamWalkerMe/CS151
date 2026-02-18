/* project2.cpp - use a vector to sort planets 
Author: Liam Walker 
Module: 1
Project: Homework 1
*/

#include "Planet.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<Planet> planets;
vector<Planet>::iterator it;

void printPlanets() {
    cout << left << setw(15) << "Planet";
    cout << left << setw(15) << "Diameter";
    cout << left << setw(13) << "Dist. to Sun";
    cout << endl;
    cout << right << setw(15) << setfill('-') << " ";
    cout << right << setw(15) << setfill('-') << " ";
    cout << right << setw(13) << setfill('-') << " " << setfill(' ');
    cout << endl;

    long long totalDiameter = 0;
    long long totalDistance = 0;

    for(int i = 0; i < planets.size(); i++) {
        totalDiameter += planets[i].getDiameter();
        totalDistance += planets[i].getDistance();

        cout << left << setw(15) << planets[i].getName();
        cout << right << setw(15) << planets[i].getDiameter();
        cout << right << setw(13) << planets[i].getDistance();
        cout << endl;
    }
        cout << setw(43) << setfill('-') << "" << setfill(' ') << endl;
        cout << left << setw(15) << "Total: ";
        cout << right << setw(15) << totalDiameter;
        cout << right << setw(13) << totalDistance;
        cout << endl;

    
    
    
}

void insert(Planet planet) {
    int position = 0;
    for(int j = 0; j < planets.size(); j++) {
            //check if random number should go between two planets in the vector
            if(planet.getDistance() < planets[j].getDistance()) {
                position = 0;
                break;
            } else if(planet.getDistance() >= planets[j].getDistance() && planet.getDistance() < planets[j+1].getDistance()) {
                position = j + 1;
                break;
            } else {
                position = planets.size();
            }
            
        }
        it = planets.begin() + position;
        planets.insert(it, planet);

}


int main() {
    Planet planet1("Ceres", 952, 413700000);
    insert(planet1);

    Planet planet2("Earth", 12756, 149600000);
    insert(planet2);

    Planet planet3("Eris", 2321, 10125000000);
    insert(planet3);

    Planet planet4("Haumea", 1220, 6452000000);
    insert(planet4);

    Planet planet5("Jupiter", 142796, 778300000);
    insert(planet5);

    Planet planet6("Makemake", 1475, 6850000000);
    insert(planet6);

    Planet planet7("Mars", 6787, 227900000);
    insert(planet7);

    Planet planet8("Mercury", 4878, 57900000);
    insert(planet8);

    Planet planet9("Neptune", 48600, 4497000000);
    insert(planet9);

    Planet planet10("Pluto", 2302, 5891000000);
    insert(planet10);

    Planet planet11("Saturn", 120660, 1427000000);
    insert(planet11);

    Planet planet12("Uranus", 51118, 2831000000);
    insert(planet12);

    Planet planet13("Venus", 12104, 108200000);
    insert(planet13);

    printPlanets();
    return 0;
}

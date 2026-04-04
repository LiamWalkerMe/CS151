/* project1.cpp - Overloading and composition
    Name: Liam Walker
    Module: 
    Project: 
    Problem Statement:

    Algorithm / Plan:
    1. Test the implementation of the EString class by creating EString objects and using the overloaded operators to manipulate them.
    2. 

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include "EString.h"
using namespace std;

int main() {
    
    //Test constructor, copy constructor, assignment operator, and stream insertion operator
    EString estring1 = "Hello Miracosta!", estring2;

    estring2 = estring1; // assignment operator

    cout << "First string:  " << estring1 << endl 
         << "Second string: " << estring2 << endl << endl; 


    // Test with punctuation and spaces
    EString estring3 = "New Year's Party at 8:30";

    // Prefix ++ demonstration
    cout << "Original string:        " << estring3 << endl;
    cout << "Using prefix operator:  " << ++estring3 << endl;
    cout << "After using prefix:     " << estring3 << endl << endl;



    // Postfix ++ demonstration
    EString estring5 = estring2 + estring3;
    cout << "Concatenated string:   " << estring5 << endl;

    // Test [] overload
    cout << "Original: ";
    for(int i = 0; i < estring3.getSize(); i++) {
        cout << estring3[i] << " ";
    }
    cout << endl;
    cout << "Updated: ";
    for(int i = 0; i < estring3.getSize(); i++) {
        cout << ++estring3[i] << " ";
    }

    
    return 0;
}
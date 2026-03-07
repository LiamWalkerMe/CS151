/* project2.cpp -  Copy Constructors
    Name: Liam Walker
    Module: 5
    Project: 2
    Problem Statement: 
    Algorithm / Plan:
    1. Follow lab instructions to learn more about classes

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>

#include "string.h"
using namespace std;

int main() {
    
    // Manipulate Strings using a constructor and an 
    // assignment statement  
    cout << "Create two strings, one using a constructor, " 
        << "another an assignment statement" << endl; 

    String str1("MiraCosta College");    // constructor
    String str2 = str1;                  // copy constructor  

    print(str1);
    print(str2);

    // Use the change function on string2 and print
    cout << "\nAfter changing string2 using change()" << endl;  
    str2.change("Cal State San Marcos"); 

    print(str1);
    print(str2);

    // Use the change function on string1 and print
    cout << "\nAfter changing string1 using change()" << endl;  
    str1.change("UCSD");

    print(str1);
    print(str2);
    

    
    return 0;
}
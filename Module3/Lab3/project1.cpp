/* project1.cpp - Dangling Pointers
    Name: Liam Walker
    Module: 3
    Project: 1
    Problem Statement: Complete the steps in the lab to understand how dangling pointers can cause issues in C++.

    Algorithm / Plan:
    1. N/A

*/
#include <iostream>
using namespace std;

int * badReturn();

int main() {
    
    // Dangling pointer issue #1
    cout << "Part #1" << endl;
    int *ptr1;
    if (true) {
        int square = 36;  
        ptr1 = &square;  
    } 
    
    *ptr1 = 49; 
    cout << "Dangling pointer: " << *ptr1 << endl << endl;

    
    // Dangling pointer issue #2 
    cout << "Part #2" << endl;
    int *ptr2 = new int(11);  

    // Now free that memory and try to use it
    delete ptr2;  
    *ptr2 = 85; 
    cout << "Dangling pointer: " << *ptr2 << endl << endl;  


    // Dangling pointer issue #3
    cout << "Part #3" << endl ;
    int *ptr3 = badReturn() ;
    cout << "Dangling pointer: " << *ptr3 << endl ; 

    // Will the value in ptr3 be re-initialized?
    *ptr3 = 45 ;
    ptr3 = badReturn() ;
    cout << "When called again: " << *ptr3 << endl ; 

    return 0;
}

// Return the address of a local variable 
int * badReturn() { 
    static int x = 19;
    return &x;
} 
 

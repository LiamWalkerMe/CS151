/* string.h -  Modified String Class
    Name: Liam Walker
    Module: 5
    Project: 2
    Problem Statement: 
    Algorithm / Plan:
    1. Follow lab instructions to learn more about classes

*/
#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <iostream>

using namespace std;

class String {
private:
    char *string;
    int size;
    
public: 
    String(const char *s = "");       // constructor 
    ~String();                        // destructor 
    void change(const char *);        // reassign string
    String(const String &);           // copy constructor
 
    // If friend function was removed the pring function would not be able to access the private member variable string.
    friend void print(const String &); // friend function  
};



// Constructor
String::String(const char *original) {  
    // stren returns the length of the string
    size = strlen(original); 
    string = new char[size + 1];
    // strcpy copies one string to another
    strcpy(string, original);  
} 

// Replace with another String object
void String::change(const char *original) {  
    delete [] string;  
    size = strlen(original); 
    string = new char[size + 1]; 
    strcpy(string, original);  // Had to change from strcpy_s due to error
}

// Copy constructor which creates a new string  
String::String(const String &original) {  
    size = original.size;  
    string = new char[size + 1];  
    strcpy(string, original.string);  
}  

String::~String() {  
    delete[] string;
    size = 0;
}

// Display a String on the console  
void print(const String &ptr) {  
    cout << ptr.string << endl;
} 

#endif
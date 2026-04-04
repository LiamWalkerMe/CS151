/* project2.cpp -  Copy Constructors
    Name: Liam Walker
    Module: 6
    Project: 1
    Problem Statement: 
    Plan:
    1. Follow lab instructions to learn more about classes

*/
#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

class EString {
private:
    char *string;
    int size;
    
public: 
    EString(const char *s = "");       // constructor 
    ~EString();                        // destructor 
    void change(const char *);        // reassign string
    EString(const EString &);           // copy constructor
    EString & operator=(const EString &); // assignment operator
    friend ostream & operator<<(ostream &, const EString &); // friend function for output stream
    int getSize() const { return size; } // getter for size
    
    EString operator++();  
    EString operator++(int); 
    char & operator[](int); 
    friend EString operator+(const EString &, const EString &);  

 
    // If friend function was removed the pring function would not be able to access the private member variable string.
    friend void print(const EString &); // friend function  
};



// Constructor
EString::EString(const char *original) {  
    // stren returns the length of the string
    size = strlen(original); 
    string = new char[size + 1];
    // strcpy copies one string to another
    strcpy(string, original);  
} 

// Replace with another String object
void EString::change(const char *original) {  
    delete [] string;  
    size = strlen(original); 
    string = new char[size + 1]; 
    strcpy(string, original);  // Had to change from strcpy_s due to error
}

// Copy constructor which creates a new string  
EString::EString(const EString &original) {  
    size = original.size;  
    string = new char[size + 1];  
    strcpy(string, original.string);  
}  

EString::~EString() {  
    delete[] string;
    size = 0;
}

// Assignment operator
EString & EString::operator=(const EString &original) {  
    delete [] string;  
    size = original.size;  
    string = new char[size + 1];  
    strcpy(string, original.string);  
    return *this; 
}

// Stream insertion operator
ostream & operator<<(ostream &out,  
                    const EString &output_EString) {  
    out << output_EString.string; 
    return out; 
}  

// Prefix ++: convert to uppercase, return *this
EString EString::operator++() {
    for(int i = 0; i < size; i++) {
        string[i] = toupper(string[i]);
    }
    return *this;
}

// Postfix ++: return copy, then convert calling object
EString EString::operator++(int) {
    EString temp = *this;
    ++(*this);
    return temp;
}

// Subscript operator: return char reference, error if out of bounds
char & EString::operator[](int index) {
    if (index < 0 || index >= size) {
        cerr << "Index out of bounds" << endl;
        exit(1);
    }
    return string[index];
}

// Addition operator: concatenate two EStrings
EString operator+(const EString &left, const EString &right) {
    int newSize = left.size + right.size;
    char *newString = new char[newSize + 1];
    strcpy(newString, left.string);
    strcat(newString, right.string);
    EString result(newString);
    delete[] newString;
    return result;
}

#endif
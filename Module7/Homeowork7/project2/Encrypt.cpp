/* Encrypt.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 7
    Project: 2
    Problem Statement: Create a class EncryptableString that inherits from the string class and includes a method encrypt() that shifts each alphanumeric character by one position in the ASCII table.

    Algorithm / Plan:
    1. Create a class EncryptableString that inherits from the string class.
    2. Implement a method encrypt() that iterates through each character in the string.

*/
#include <string>
#ifndef ENCRYPT_H
#define ENCRYPT_H
using namespace std;

class EncryptableString : public string {
public:
    // Constructor that takes a string object
    EncryptableString(const string& str) : string(str) {}
    
    // Constructor that takes a C-string
    EncryptableString(const char* cstr) : string(cstr) {}
    
    // Default constructor
    EncryptableString() : string() {}

    void encrypt();
    
};
#endif

void EncryptableString::encrypt() {
    for (int i = 0; i < length(); i++) {
        if (isalnum((*this)[i])) {
            char c = (*this)[i];
            if (c == 'z') {
                (*this)[i] = 'a';
            } else if (c == 'Z') {
                (*this)[i] = 'A';
            } else if (c == '9') {
                (*this)[i] = '0';
            } else {
                (*this)[i]++;
            }
        }
    }
}
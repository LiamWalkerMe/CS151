/* PString.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 7
    Project: 1
    Problem Statement: Create a class PString that inherits from the string class and includes a method isPalindrome() that checks if the string is a palindrome.

    Algorithm / Plan:
    1. Create a class PString that inherits from the string class.

*/
#ifndef PSTRING_H
#define PSTRING_H
#include <string>
#include <iostream>


using namespace std;

class PString : public string {
    public:
        // Constructor that takes a string object
        PString(const string& str) : string(str) {}
        
        // Constructor that takes a C-string
        PString(const char* str) : string(str) {}
        
        // Default constructor
        PString() : string() {}

        // Method to check if the string is a palindrome
        bool isPalindrome();

    private:

};


bool PString::isPalindrome() {
    int left = 0;
    int right = this->length() - 1;
    // needs to ignore spaces and punctuation, and be case-insensitive
    while (left < right) {
        // Skip non-alphanumeric characters from the left
        while (left < right && !isalnum(this->at(left))) {
            left++;
        }
        // Skip non-alphanumeric characters from the right
        while (left < right && !isalnum(this->at(right))) {
            right--;
        }
        // Compare characters in a case-insensitive manner
        if (tolower(this->at(left)) != tolower(this->at(right))) {
            // If characters do not match, the string is not a palindrome
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}


#endif
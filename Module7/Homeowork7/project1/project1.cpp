/* project1.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 7
    Project: 1
    Problem Statement: Create a class PString that inherits from the string class and includes a method isPalindrome() that checks if the string is a palindrome.
 
    Algorithm / Plan:
    1. Define the PString class that inherits from string.
    2. Implement constructors for PString to initialize the string.
    3. Implement the isPalindrome() method to check if the string is a palindrome, ignoring spaces, punctuation, and case.
    4. In the main function, prompt the user to enter a string and create a PString object with the input.
    5. Call the isPalindrome() method and display whether the string is a palindrome or not.

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include "PString.cpp"
using namespace std;

int main() {
    
    while(true) {
        string input;
        cout << "Enter a string (or '-1' to quit): ";
        getline(cin, input);
        
        if (input == "-1") {
            break;
        }
        
        PString pstr(input);
        if (pstr.isPalindrome()) {
            cout << "'" << input << "' is a palindrome." << endl;
        } else {
            cout << "'" << input << "' is not a palindrome." << endl;
        }
    }

    return 0;
}
/* project1.cpp - String Encryption Program
    Name: Liam Walker
    Module: 8
    Project: 1
    Problem Statement:
    Encrypt strings by rotating letters and digits by one position.

    Algorithm / Plan:
    1. Read user input in a loop.
    2. Stop when the user types "quit".
    3. Show original input.
    4. Encrypt once and show result.
    5. Encrypt again and show twice-encrypted result.

*/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <memory>
#include <random>
using namespace std;

void encrypt(char &character);

int main() {

    string message;
    string quit_test;
    while (true) {
        cout << "Please enter a string to encrypt: ";
        getline(cin, message);
        
        quit_test = message;

        // Convert copy to lowercase to check for "quit".
        for_each(quit_test.begin(), quit_test.end(),  
        [](char &c) { c = tolower(c); } ); 

        if (quit_test == "quit") {
            cout << "Exiting program." << endl;
            break;
        }

        cout << "Original string: " << message << endl;

        // Encrypt the string once.
        for_each(message.begin(), message.end(), 
        [](char &c) { encrypt(c); } );   
        cout << "Encrypted string: " << message << endl;

        // Encrypt the string again.
        for_each(message.begin(), message.end(), 
        [](char &c) { encrypt(c); } );   
        cout << "Twice Encrypted string: " << message << endl;

    }

    
    

    return 0;
}

void encrypt(char &character) {  
    // Rotate letters and digits by one, with wraparound.
    if (isalnum(character)) {
        if (character == 'z') {
            character = 'a';
        } else if (character == 'Z') {
            character = 'A';
        } else if (character == '9') {
            character = '0';
        } else {
            character++;
        }
    }
}
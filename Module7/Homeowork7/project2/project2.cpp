/* project2.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 7
    Project: 2
    Problem Statement: 

    Algorithm / Plan:
    1. Prompt the user to enter a string to encrypt, or '-1' to quit.
    2. If the user enters '-1', exit the loop and end the program.
    3. Create an EncryptableString object using the user's input.
    4. Display the original string.
    5. Call the encrypt() method on the EncryptableString object to encrypt it once.
    6. Display the encrypted string after the first encryption.
    7. Call the encrypt() method again to encrypt the string a second time.
    8. Display the encrypted string after the second encryption.

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include "Encrypt.cpp"
using namespace std;

int main() {
    
    while(true) {
        cout << "Enter a string to encrypt (or '-1' to quit): ";
        string input;
        getline(cin, input);
        if (input == "-1") {
            break;
        }
        EncryptableString str(input);
        cout << "Original String: " << str << endl;
        str.encrypt();
        cout << "Encrypted Once: " << str << endl;
        str.encrypt();
        cout << "Encrypted Twice: " << str << endl << endl;
    }


    return 0;
}
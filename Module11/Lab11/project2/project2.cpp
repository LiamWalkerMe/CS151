/* project2.cpp - Binary to Decimal Converter
    Name: Liam Walker
    Module: 11
    Project: 2
    Problem Statement: Write a program that prompts the user for a positive binary string and then displays the decimal representation of that binary string using both a recursive and an iterative function.

    Algorithm / Plan:
    1. Prompt the user for a positive binary string and read the input.
    2. Call both the recursive and iterative functions to convert the input to decimal and display the results.
    3. Implement the recursive function to convert a binary string to decimal.
    4. Implement the iterative function to convert a decimal number to binary.


*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
using namespace std;

int recursiveBinaryToDecimal(string n);
int iterativeBinaryToDecimal(string n);

int main() {
    
    // Prompt the user for a positive binary string and read the input
    cout << "Please enter a positive binary string: ";
    string n;
    cin >> n;

    // Call both the recusive and iterative functions
    cout << "The decimal representation using recursion of " << n << " is: " << recursiveBinaryToDecimal(n) << endl;
    cout << "The decimal representation using iteration of " << n << " is: " << iterativeBinaryToDecimal(n) << endl;



    return 0;
}

int recursiveBinaryToDecimal(string s) {
    // Base Case: If the string has only one character left
    if (s.length() == 1) {
        // Convert '0'/'1' to int 0/1 manually
        return s[0] - '0'; 
    }

    // Solve the rest of the string, using ASCII table math to convert to string
    int leadingValue = recursiveBinaryToDecimal(s.substr(0, s.length() - 1));
    
    // Manual conversion of the last character
    int lastDigit = s[s.length() - 1] - '0'; 

    // Now you are adding int + int, which C++ likes!
    return (leadingValue * 2) + lastDigit;
}

int iterativeBinaryToDecimal(string n) {
    int decimalValue = 0;
    for (int i = 0; i < n.length(); i++) {
        int digit = n[i] - '0';
        decimalValue = decimalValue * 2 + digit;
    }
    return decimalValue;
}

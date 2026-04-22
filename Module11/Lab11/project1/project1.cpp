/* project1.cpp - Decimal to Binary Converter
    Name: Liam Walker
    Module: 11
    Project: 1
    Problem Statement: Write a program that prompts the user for a positive integer and then displays the binary representation of that integer using both a recursive and an iterative function.

    Algorithm / Plan:
    1. Prompt the user for a positive integer and read the input.
    2. Call both the recusive and iterative functions to convert the input to binary and display the results.
    3. Implement the recursive function to convert a decimal number to binary.
    4. Implement the iterative function to convert a decimal number to binary.


*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
using namespace std;

string recursiveDecimalToBinary(int n);
string iterativeDecimalToBinary(int n);

int main() {
    
    // Prompt the user for a positive integer and read the input
    cout << "Please enter a positive integer: ";
    int n;
    cin >> n;

    // Call both the recusive and iterative functions
    cout << "The binary representation using recursion of " << n << " is: " << recursiveDecimalToBinary(n) << endl;
    cout << "The binary representation using iteration of " << n << " is: " << iterativeDecimalToBinary(n) << endl;



    return 0;
}

string recursiveDecimalToBinary(int n) {
    // base case is reached when n / 2 is 0.
    //  handle n == 0 specifically to avoid an empty string for the input 0.
    if (n == 0) {
        return "0";
    }
    
    // If last division reached (n is 1), return just that digit
    if (n == 1) {
        return "1";
    }

    // Divide n by 2 (recursive call), Get the remainder (n % 2), Convert remainder to char: (n % 2 + '0')
    return recursiveDecimalToBinary(n / 2) + char(n % 2 + '0');
}

string iterativeDecimalToBinary(int n) {

    //setup variables to hold the remainder, modulus, and digit character. Also setup an empty string to hold the result.
    int remainder = 0;
    int modulus = 0;
    char digit = (remainder + '0');
    string result = "";

    // handle n == 0 specifically to avoid an empty string for the input 0.
    if(n == 0) return "0";

    // loop until n is reduced to 0, in each iteration get the modulus (n % 2) and the remainder (n / 2), 
    // convert the modulus to a char and add it to the front of the result string.
    while(n > 0) {
        
        modulus = n % 2;
        remainder = n / 2;
        n = remainder;
        digit = (modulus + '0');
        result = digit + result;
    }

    return result;

}
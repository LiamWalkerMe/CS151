/* project1.cpp - Recursive Factorial Calculator
    Name: Liam Walker
    Module: 11
    Project: 1
    Problem Statement: Write a program that prompts the user for a positive integer and then displays the factorial of that integer using a recursive function.

    Algorithm / Plan:
    1. Prompt the user for a positive integer and read the input.
    2. Call the recursive function to calculate the factorial of the input and display the result.
    3. Implement the recursive function to calculate the factorial of a number, with a base case for 0 and 1, and a recursive case for n > 1.
    4. Handle negative input by displaying an error message and exiting the program.

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
using namespace std;


long long recursiveFactoral(long long n);

int main() {

    long long n = 0;
    
    // Prompt the user for a positive integer and read the input
    while (true) {
        cout << "Please enter a positive integer: ";
        long long n;
        cin >> n;

        // Handle negative input by displaying an error message and exiting the program.
        if (n < 0) {
            cout << "Negative input received. Exiting program." << endl;
            break;
        }

        // Call the recursive function to calculate the factorial of the input and display the result.
        cout << "The factorial of " << n << " is: " << recursiveFactoral(n) << endl;


    }
    


    return 0;
}

// Implement the recursive function to calculate the factorial of a number, with a base case for 0 and 1, and a recursive case for n > 1.
long long recursiveFactoral(long long n) {
    // Base Case: If n is 0 or 1, return 1
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive Case: n! = n * (n - 1)!
    return n * recursiveFactoral(n - 1);
}
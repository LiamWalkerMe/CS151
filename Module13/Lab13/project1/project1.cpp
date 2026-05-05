/* project.cpp - Challenge #2
    Name: Liam Walker
    Module: 13
    Project: 1
    Problem Statement: Write a function that returns the integer square root of a perfect square,
                throwing an exception for non-perfect squares.

    Algorithm / Plan:
    1. Create a custom exception class for non-perfect squares
    2. Implement integerSquareRoot() function that checks if input is a perfect square
    3. If perfect square, calculate and return the square root
    4. If not perfect square, throw the custom exception
    5. In main(), use try-catch to handle the exception
    6. Loop through numbers 0-25 and test each with the function
    7. Print results: square root if perfect, error message if not

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include <cmath>
using namespace std;

// Custom exception class for non-perfect squares
class NotPerfectSquareException : public exception {
public:
    NotPerfectSquareException(int num) : number(num) {}
    
    const char* what() const noexcept override {
        return "Input is not a perfect square";
    }
    
    int getNumber() const {
        return number;
    }
    
private:
    int number;
};


int integerSquareRoot(int num) {
    // Check for negative input
    if (num < 0) {
        throw NotPerfectSquareException(num);
    }
    
    int root = static_cast<int>(sqrt(num));
    
    if (root * root == num) {
        return root;
    } else {
        throw NotPerfectSquareException(num);
    }
}

int main() {
    // Test the integerSquareRoot function with numbers 0-25
    for (int i = 0; i <= 25; i++) {
        try {
            int root = integerSquareRoot(i);
            cout << i << " is a perfect square. Square root: " << root << endl;
        } catch (const NotPerfectSquareException& e) { // Catch the custom exception
            cout << e.getNumber() << " is not a perfect square." << endl;
        }
    }
    
    return 0;
}
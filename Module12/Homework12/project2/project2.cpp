/* project.cpp - Abstract Sequence Class with Even and Factorial Implementations
    Name: Liam Walker
    Module: 12
    Project: 2
    Problem Statement: 

    Algorithm / Plan:
    1. Create an abstract base class AbstractSeq with pure virtual function fun(int value) and member functions printSeq(int low, int high) and sumSeq(int low, int high).
    2. Implement printSeq to display the sequence values from low to high.
    3. Implement sumSeq to calculate the sum of the sequence values from low to high
    4. Create a derived class EvenSeq that overrides fun to return the nth even number.
    5. Create a derived class FactorialSeq that overrides fun to return the factorial of
    the given value.
    6. In the main function, create instances of EvenSeq and FactorialSeq, and use them to display the sequences and their sums as specified.


*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
using namespace std;

class AbstractSeq {

    public:
        void printSeq(int low, int high);
        int sumSeq(int low, int high);
        virtual int fun(int value) = 0;

};

class EvenSeq : public AbstractSeq {
public:
// Override the fun function to return the nth even number
    virtual int fun(int value) override {
        return 2 * value;
    }
};

class FactorialSeq : public AbstractSeq {
public:

// Override the fun function to return the factorial of the given value
    virtual int fun(int value) override {
        if (value <= 0) return 1;
        int result = 1;
        for (int i = 1; i <= value; i++) {
            result *= i;
        }
        return result;
    }
};

void AbstractSeq::printSeq(int low, int high) {
    // Print the header
    cout << "n      fun(n)" << endl;
    cout << "-----  ----------" << endl;
    // Print the sequence values from low to high
    for (int i = low; i <= high; i++) {
        cout << left << setw(7) << i << fun(i) << endl;
    }
}

// Define sumSeq outside the class
int AbstractSeq::sumSeq(int low, int high) {
    // Calculate the sum of the sequence values from low to high
    int total = 0;
    // Loop through the range and accumulate the sum using the fun function
    for (int i = low; i <= high; i++) {
        total += fun(i);
    }
    return total;
}



int main() {
    // Even Numbers Sequence
    EvenSeq even;
    cout << "Even numbers fun(3) to fun(12) are:" << endl;
    even.printSeq(3, 12);
    cout << "The sum of fun(7) to fun(10) is " << even.sumSeq(7, 10) << endl << endl;

    // Factorial Sequence
    FactorialSeq fact;
    cout << "Factorial numbers fun(1) to fun(10) are:" << endl;
    fact.printSeq(1, 10);
    cout << "The sum of factorials from fun(4) to fun(6) is " << fact.sumSeq(4, 6) << endl;

    return 0;
}

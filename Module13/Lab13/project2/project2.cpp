/* project.cpp - Template Accumulator Function
    Name: Liam Walker
    Module: 13
    Project: 2
    Problem Statement:
    Create a template function that accumulates (sums) elements in a vector.
For numeric types, returns the arithmetic sum; for strings, returns concatenation.

    Algorithm / Plan:
    1. Create template function accum that takes a vector<T> parameter
    2. Initialize result with T() default constructor (0 for numeric, "" for string)
    3. Loop through all vector elements and accumulate using += operator
    4. Return the accumulated result
    5. In main, test with vector of 5+ ints
    6. In main, test with vector of 5+ doubles
    7. In main, test with vector of 5+ strings
    8. Display vector contents and sum for each test case

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include <vector>
#include <string>
using namespace std;

template <typename T>
T accum(vector<T> v) {
    T result = T();
    for (int i = 0; i < v.size(); i++) {
        result += v[i];
    }
    return result;
}

int main() {
    // Test with vector of ints
    vector<int> intVec = {10, 20, 30, 40, 50};
    cout << "Integer vector: ";
    for (int num : intVec) {
        cout << num << " ";
    }
    cout << "\nSum of integers: " << accum(intVec) << "\n\n";

    // Test with vector of doubles
    vector<double> doubleVec = {1.5, 2.5, 3.5, 4.5, 5.5};
    cout << "Double vector: ";
    for (double num : doubleVec) {
        cout << num << " ";
    }
    cout << "\nSum of doubles: " << accum(doubleVec) << "\n\n";

    // Test with vector of strings
    vector<string> stringVec = {"Hello", " ", "World", " ", "Program"};
    cout << "String vector: ";
    for (const string& str : stringVec) {
        cout << str << " ";
    }
    cout << "\nConcatenation of strings: " << accum(stringVec) << "\n";

    return 0;
}
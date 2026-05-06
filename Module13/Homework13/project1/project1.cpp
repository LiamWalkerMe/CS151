/* project.cpp - BCheckString Class with Bounds Checking
    Name: Liam Walker
    Module:  13
    Project: 1
    Problem Statement:
    Create a class BCheckString derived from string with bounds-checked operator[]

    Algorithm / Plan:
    1. Define BoundsException class inside BCheckString
    2. Define BCheckString constructor that calls base string constructor
    3. Implement operator[] with bounds checking
    4. Throw BoundsException if index is negative or >= string length
    5. Return character if index is valid
    6. Test with valid indices
    7. Test with negative index
    8. Test with index too large
    9. Display results and exception messages

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include <exception>
using namespace std;

class BCheckString : public string {
public:
    class BoundsException : public exception {
    private:
        string message;
    public:
        BoundsException(int k) {
            message = "Index " + to_string(k) + " is out of bounds";
        }
        const char* what() const noexcept override {
            return message.c_str();
        }
    };

    BCheckString(string s) : string(s) {}

    char operator[](int k) {
        if (k < 0 || k >= length()) {
            throw BoundsException(k);
        }
        return string::operator[](k);
    }
};

int main() {
    BCheckString test("Hello");
    
    cout << "Test string: " << test << endl;
    cout << "String length: " << test.length() << endl << endl;
    
    // test 1: Valid index within bounds
    try {
        cout << "Accessing index 0: " << test[0] << endl;
    } catch (BCheckString::BoundsException& e) {
        cout << "Exception: " << e.what() << endl;
    }
    
    // test 2: Valid index within bounds
    try {
        cout << "Accessing index 4: " << test[4] << endl;
    } catch (BCheckString::BoundsException& e) {
        cout << "Exception: " << e.what() << endl;
    }
    
    cout << endl;
    
    // test 3: Negative index
    try {
        cout << "Accessing index -1: " << test[-1] << endl;
    } catch (BCheckString::BoundsException& e) {
        cout << "Exception caught - " << e.what() << endl;
    }
    
    // test 4: Index too large
    try {
        cout << "Accessing index 10: " << test[10] << endl;
    } catch (BCheckString::BoundsException& e) {
        cout << "Exception caught - " << e.what() << endl;
    }

    return 0;
}
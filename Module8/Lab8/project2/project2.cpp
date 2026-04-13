/* project2.cpp - Number/String/Base Conversion Lab
    Name: Liam Walker
    Module: 8
    Project: 2
    Problem Statement:
    Read in an integer, convert it to and from several string formats,
    and display the results in decimal, binary, and hexadecimal.

    Algorithm / Plan:
    1. Prompt the user for an integer and read it into original.
    2. Stop early if the input is invalid.
    3. Stop early if the number is negative because this lab's binary
       conversion is intended for non-negative values.
    4. Convert the number to a C++ string with to_string.
    5. Add " rah!" to the end of the string and print it.
    6. Use a stringstream to convert the string back to a number.
    7. Build a binary C-string one digit at a time and print it.
    8. Use stoi with base 2 to convert the binary string back to decimal.
    9. Use a stringstream and the hex manipulator to convert to hexadecimal.
    10. Read the hexadecimal value back into decimal and print the result.

*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    // Get integer from user
    int original = 0;
    cout << "Please enter a non-negative integer: ";
    cin >> original;

    // Validate input
    if (!cin) {
        cout << "Invalid input. Please run the program again and enter an integer." << endl;
        return 1;
    }

    // Check for non-negative value
    if (original < 0) {
        cout << "Please run the program again and enter a non-negative integer." << endl;
        return 0;
    }

    // Convert to string and append " rah!"
    string original_as_string = to_string(original) + " rah!";
    cout << "Number as a string: " << original_as_string << endl;

    // Extract number back from string (stops at space)
    stringstream inpstr(original_as_string);
    int original_copy = 0;
    inpstr >> original_copy;
    cout << "Converted back to a number: " << original_copy << endl;

    // Allocate array for binary digits (32 bits + null terminator)
    char *binary = new char[33];
    *(binary + 32) = '\0';

    // Fill array from back to front for correct digit order
    int index = 32;
    int binary_source = original_copy;

    // Convert to binary: repeatedly divide by 2, save remainder as '0'/'1'
    // Do-while ensures 0 still produces "0"
    do {
        *(binary + (--index)) = static_cast<char>(binary_source % 2 + '0');
        binary_source /= 2;
    } while (binary_source > 0);

    // Print the binary representation
    cout << "That number in binary is: " << (binary + index) << endl;

    // Convert binary string back to decimal using stoi with base 2
    original_copy = stoi((binary + index), nullptr, 2);
    cout << "Binary converted back to decimal: " << original_copy << endl;

    // Convert to hexadecimal using stringstream and hex manipulator
    stringstream iostr;
    iostr << hex << original;
    cout << "That number in hexadecimal is: " << iostr.str() << endl;

    // Convert hexadecimal back to decimal
    iostr.seekg(0);
    iostr >> hex >> original_copy;
    cout << "Hex converted back to decimal: " << original_copy << endl;

    // Free allocated memory
    delete[] binary;

    return 0;
}

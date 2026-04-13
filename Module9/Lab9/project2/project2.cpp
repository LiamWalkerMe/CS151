/* project.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 9
    Project: 2
    Problem Statement:  

    Algorithm / Plan:
    1. Follow steps to learn more about advanced I/O techniques in C++.

*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    // Binary data file created by project 1.
    const string FILENAME = "array.dat";

    // Open the file for both reading and writing in binary mode.
    fstream data_file(FILENAME, ios::binary | ios::in | ios::out) ;  
    
    if (! data_file) { 
        cout << "Error: Could not open file " << FILENAME << endl;
        return 1;
    } 

    cout << "Please enter a multiplier: ";
    double multiplier;
    cin >> multiplier;

    // Track the current byte position in the file.
    streamoff position = 0;

    cout << "Reading and updating ints..." << endl;

    for (int i = 0; i < 10; i++) { 
        // Move to the next int, read it, update it, and write it back.
        data_file.seekg(position, ios::beg);
        int original_value;
        data_file.read(reinterpret_cast<char *>(&original_value), sizeof(int));
        int updated_value = static_cast<int>(round(original_value * multiplier));
        data_file.seekp(position, ios::beg);
        data_file.write(reinterpret_cast<const char *>(&updated_value), sizeof(int));
        cout << original_value << " -> " << updated_value << endl;
        position += sizeof(int);
    }

    cout << endl << "Reading doubles..." << endl;

    for (int i = 0; i < 10; i++) { 
        // Repeat the same process for the 10 double values.
        data_file.seekg(position, ios::beg);
        double original_value;
        data_file.read(reinterpret_cast<char *>(&original_value), sizeof(double));
        double updated_value = original_value * multiplier;
        data_file.seekp(position, ios::beg);
        data_file.write(reinterpret_cast<const char *>(&updated_value), sizeof(double));

        // Show which number this square root now corresponds to.
        double root = updated_value * updated_value;
        cout << original_value << " -> " << updated_value << " (root of ";
        if (fabs(root - round(root)) < 1e-9) {
            cout << static_cast<long long>(llround(root));
        } else {
            cout << root;
        }
        cout << ")" << endl;

        position += sizeof(double);
    }

    data_file.close();
    return 0;
}

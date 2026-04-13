/* project.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 9
    Project: 1
    Problem Statement: 

    Algorithm / Plan:
    1. Follow the steps to learn more about advanced I/O techniques in C++.

*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    const string FILENAME = "array.dat";

    ofstream data_file(FILENAME, ios::binary | ios::out);
    // Check if the file was opened successfully.
    if (! data_file) { 
        cout << "Error: Could not open file " << FILENAME << endl;
        return 1;
    } 
    // Write 10 ints and 10 doubles to the file.
    for (int i = 1; i <= 10; i++) { 
        data_file.write(reinterpret_cast<const char *>(&i), sizeof(int));
    } 
    
    for (int i = 1; i <= 10; i++) { 
        double square_root = sqrt(static_cast<double>(i));
        data_file.write(reinterpret_cast<const char *>(&square_root), sizeof(double));
    }
    // Close the file after writing.
    data_file.close();
    return 0;
}

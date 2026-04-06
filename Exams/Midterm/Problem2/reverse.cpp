/* reverse.cpp - Reverse each line in a text file
 * Author:     Liam Walker
 * Module:     10
 * Project:    Midterm Problem 2
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Set the file path
    const string fileName = "/Users/liamwalker/Documents/Github/CS151 - Local/Midterm/Problem2/JFK Speech.txt";

    // Open file for reading
    ifstream input(fileName);
    if (!input) {
        cerr << "Failed to open JFK Speech.txt for reading\n";
        return 1;
    }

    // Store reversed text and temporary line
    string reversedText;
    string line;

    // Read each line and reverse it
    while (getline(input, line)) {
        // Reverse the current line by iterating backwards
        for (int i = static_cast<int>(line.length()) - 1; i >= 0; i--) {
            reversedText += line[i];
        }
        reversedText += '\n';  // Add newline after reversed line
    }

    // Close input file
    input.close();

    // Open file for writing
    ofstream output(fileName);
    if (!output) {
        cerr << "Failed to open JFK Speech.txt for writing\n";
        return 1;
    }

    // Write the reversed text back to file
    output << reversedText;
    output.close();

    return 0;
}

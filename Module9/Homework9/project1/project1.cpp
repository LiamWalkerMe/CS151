/* project.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 
    Project: 
    Problem Statement:

    Algorithm / Plan:
    1.
    2.
    3.
    4.
    5.
    6.
    7.
    8.
    9.
    10.

*/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    
    cout << "Please enter the name of the file to read: ";
    string fileName;
    getline(cin, fileName);

    cout << "Please enter the name of the file to write: ";
    string outputFileName;
    getline(cin, outputFileName);

    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    string line;
    char ch;
    while (inputFile.get(ch)) {
        static bool beginningOfSentence = true;

        if (isalpha(ch)) { // checks if the character is a letter
            if (beginningOfSentence) { // checks if it's the beginning of a sentence
                ch = toupper(ch);
                beginningOfSentence = false;
            } else if (ch == 'I' && (inputFile.peek() == ' ' || inputFile.peek() == EOF)) { // checks if 'I' is surrounded by spaces or at end of file 
                ch = toupper(ch);
            } else { // converts the character to lowercase
                ch = tolower(ch);
            }
            ofstream outputFile(outputFileName, ios::app);
            outputFile << ch;
            outputFile.close();
        } else { // if the character is not a letter, just output it and check if it's a sentence-ending punctuation
            ofstream outputFile(outputFileName, ios::app);
            outputFile << ch;
            outputFile.close();

            if (ch == '.' || ch == '!' || ch == '?') {
                beginningOfSentence = true;
            }
        }
    }


    
    inputFile.close();

    return 0;
}

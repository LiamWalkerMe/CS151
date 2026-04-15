/* project.cpp - Text Correction
    Name: Liam Walker
    Module: 9
    Project: 1
    Problem Statement:
    Create a program that reads text from an input file and writes the
    corrected text to an output file. The program should capitalize the
    first letter of each sentence, keep the pronoun I uppercase when it
    appears by itself, and convert other letters to lowercase.

    Algorithm / Plan:
    1. Include the headers needed for console input and file input/output.
    2. Ask the user for the name of the file to read.
    3. Ask the user for the name of the file to write.
    4. Open the input file and display an error message if it cannot be opened.
    5. Read the input file one character at a time.
    6. Track whether the current character is at the beginning of a sentence.
    7. If the character is a letter and it starts a sentence, convert it to uppercase.
    8. If the character is a standalone I, keep it uppercase; otherwise convert letters to lowercase.
    9. Write each processed character to the output file and copy non-letter characters unchanged.
    10. When a period, exclamation point, or question mark is found, mark the next letter as the start of a new sentence.

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

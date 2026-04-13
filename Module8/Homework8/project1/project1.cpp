/* project.cpp - WORD COUNTER
    Name: Liam Walker
    Module: 8
    Project: 1
    Problem Statement:
    Read four C-style strings from the user and count how many words each string contains.

    Algorithm / Plan:
    1. Include iostream for input/output operations.
    2. Define countWords(const char*) to count space-separated words in a string.
    3. In countWords, initialize count to 0 and inWord to false.
    4. Use strlen to determine the string length and scan each char.
    5. Increment count when a new word begins and track word state with inWord.
    6. In main, read four lines with cin.getline, count the words, and print the result.
*/
#include <iostream>
#include <iomanip> // included by template; not used in this program
#include <memory>  // included by template; not used in this program
#include <random>  // included by template; not used in this program
using namespace std;

// countWords: return the number of words in a null-terminated C-string.
// A word is one or more characters separated by spaces.

int countWords(const char* str);

int main() {
    const int MAX_SIZE = 256;
    char input[MAX_SIZE];
    
    // Read four lines and report how many words each line contains.
    for (int i = 0; i < 4; ++i) {
        cout << "Enter a C-string: ";
        cin.getline(input, MAX_SIZE);
        int words = countWords(input);
        cout << "Number of words: " << words << endl;
    }
    return 0;
}

int countWords(const char* str) {
    int count = 0;
    bool inWord = false;
    size_t len = strlen(str);
    
    // Loop through each character in the string
    for (size_t i = 0; i < len; ++i) {
        // If character is not a space and we're starting a new word
        if (str[i] != ' ') {
            if (!inWord) {
                count++;
                inWord = true;
            }
        } else {
            // Space marks end of word
            inWord = false;
        }
    }
    return count;
}
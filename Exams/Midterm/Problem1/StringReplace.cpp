/* StringReplace.cpp - Replace all occurrences of one C-String with another
 * Author:     Liam Walker
 * Module:     10
 * Project:    Midterm Problem 1
 * Problem statement: Replace all occurrences of one C-String with another C-String
 *   in an original C-String
 */

#include <iostream>
#include <cstring>
using namespace std ;

// prototype
void replaceSubstring(char *, char *, char *) ;

int main() {

    // Define three C-strings, the original string, the one to replace, and the replacement
    char original[250] ;
    char source[50] ;
    char target[50] ;

    while (true) {

        // Get the original C-string
        cout << "Enter the original string or \"quit\" to stop:   " ;
        cin.getline(original, 250) ;

        // Stop if the user enters "quit"
        if (strcmp(original, "quit") == 0)
            { break ; }

        cout << "Enter the substring to replace: " ;
        cin.getline(source, 50) ;

        cout << "Enter its replacement:          " ;
        cin.getline(target, 50) ;

        // Call the function to replace all occurrences of source with target
        // in the original string, print the updated string and repeat loop
        replaceSubstring(original, source, target) ;
        cout << "With all replacements made:  " << original << endl << endl ;
    }
}

// Function to be defined
void replaceSubstring(char *original, char *source, char *target) {
    for (char *p = original ; *p != '\0' ; p++) {
        if (strncmp(p, source, strlen(source)) == 0) {
            // Shift the remaining characters to make room for the target string
            memmove(p + strlen(target), p + strlen(source), strlen(p + strlen(source)) + 1) ;
            // Copy the target string into the original string at the current position
            memcpy(p, target, strlen(target)) ;
            // Move the pointer forward by the length of the target string
            p += strlen(target) - 1 ;
        }
    }
}

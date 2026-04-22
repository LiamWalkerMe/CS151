/* project.cpp - Palindrome Checker
    Name: Liam Walker
    Module: 11
    Project: 3
    Problem Statement: Write a program that prompts the user for a string and then determines whether that string is a palindrome, ignoring spaces, punctuation, and capitalization. The program should continue to prompt the user for strings until an empty string is entered.

    Algorithm / Plan:
    1.  Prompt the user for a string and read the input.
    2. Call a recursive function to determine if the string is a palindrome, passing the string and the initial lower and upper indices.
    3. Implement the recursive function to check if the string is a palindrome by comparing characters at the lower and upper indices, ignoring non-alphanumeric characters and case. The base case is when the lower index meets or exceeds the upper index, indicating that we've checked all character pairs.
    4. If the characters at the lower and upper indices are not alphanumeric, skip them by adjusting the indices accordingly and making a recursive call.
    5. If the characters at the lower and upper indices are alphanumeric but do not match (ignoring case), return false.
    6. If the characters at the lower and upper indices match, move both indices inward and make a recursive call to continue checking.

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
using namespace std;

bool isPalindrome(string str, int lower, int upper);

int main() {
    // Prompt the user for a string and read the input
    while (true) {
        cout << "Please enter a string: ";
        string str;
        getline(cin, str);
        if (str.empty()) {
            break;
        }
        // Call a recursive function to determine if the string is a palindrome
        if (isPalindrome(str, 0, static_cast<int>(str.length()) - 1)) {
            cout << str << " is a palindrome." << endl;
        } else {
            cout << str << " is not a palindrome." << endl;
        }
    }


    return 0;
}

bool isPalindrome(string str, int lower, int upper) {
    // Base case: we've met or crossed in the middle
    if (lower >= upper) {
        return true;
    }

    // If left char isn't alphanumeric, skip it by moving lower index forward
    if (!isalnum(str[lower])) {
        return isPalindrome(str, lower + 1, upper);
    }

    //If right char isn't alphanumeric, skip it by moving upper index back
    if (!isalnum(str[upper])) {
        return isPalindrome(str, lower, upper - 1);
    }

    //Now that we know both are alphanumeric, compare them (case-insensitive)
    if (tolower(str[lower]) != tolower(str[upper])) {
        return false;
    }

    // If they match then move both indices inward.
    return isPalindrome(str, lower + 1, upper - 1);
}
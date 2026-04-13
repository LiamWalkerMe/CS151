/* project2.cpp - Password Verification
    Name: Liam Walker
    Module: 8
    Project: 2
    Problem Statement:
    Ask the user for passwords and verify whether each password meets
    the required rules for length, uppercase letters, lowercase letters,
    digits, and blanks.

    Algorithm / Plan:
    1. Include the headers needed for strings, vectors, character tests,
       and input/output.
    2. Write a password verification function that accepts a string and
       a vector used to store any failed requirements.
    3. In the function, check the password length.
    4. Loop through each character to detect uppercase letters,
       lowercase letters, digits, and blanks.
    5. Add a message to the failed requirements list for every rule that
       is not satisfied.
    6. Return true if the failed requirements list is empty.
    7. In main, prompt the user to enter the five passwords required by
       the assignment using getline.
    8. Call the password verification function for each password.
    9. Display whether the password was accepted or rejected.
    10. If rejected, print every requirement the password failed.
*/
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool verifyPassword(const string& password, vector<string>& failedRequirements);

int main() {
    // Requested
    const string requiredPasswords[5] = {
        "alfred",
        "OLIVIA",
        "12345",
        "Pass  9",
        "Mannix12"
    };

    string password;
    vector<string> failedRequirements;

    // Ask the user to enter each required test password.
    for (int i = 0; i < 5; ++i) {
        cout << "Enter password #" << (i + 1)
             << " (" << requiredPasswords[i] << "): ";

        // getline is used so passwords with spaces can be read correctly.
        getline(cin, password);

        bool accepted = verifyPassword(password, failedRequirements);

        cout << "Password entered: \"" << password << "\"" << endl;

        if (accepted) {
            cout << "Password accepted." << endl;
        } else {
            cout << "Password rejected. Requirements not met:" << endl;

            for (const string& requirement : failedRequirements) {
                cout << "- " << requirement << endl;
            }
        }

        cout << endl;
    }

    return 0;
}

bool verifyPassword(const string& password, vector<string>& failedRequirements) {
    // Start with an empty list so old results are not reused.
    failedRequirements.clear();

    // These flags track which required character types appear.
    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;
    bool hasBlank = false;

    // Check every character in the password.
    for (char character : password) {
        unsigned char current = static_cast<unsigned char>(character);

        if (isupper(current)) {
            hasUppercase = true;
        }

        if (islower(current)) {
            hasLowercase = true;
        }

        if (isdigit(current)) {
            hasDigit = true;
        }

        // A blank space is not allowed in the password.
        if (isspace(current)) {
            hasBlank = true;
        }
    }

    // Add every rule that the password did not satisfy.
    if (password.length() < 6) {
        failedRequirements.push_back("Password must be at least six characters long.");
    }

    if (!hasUppercase) {
        failedRequirements.push_back("Password must contain at least one uppercase letter.");
    }

    if (!hasLowercase) {
        failedRequirements.push_back("Password must contain at least one lowercase letter.");
    }

    if (!hasDigit) {
        failedRequirements.push_back("Password must contain at least one digit.");
    }

    if (hasBlank) {
        failedRequirements.push_back("Password cannot contain any blanks.");
    }

    // If nothing failed, then the password is valid.
    return failedRequirements.empty();
}
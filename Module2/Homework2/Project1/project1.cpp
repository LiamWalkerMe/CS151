/* project1.cpp - Decimal-to-Binary Converter
    Name: Liam Walker
    Module: 2
    Project: Homework2
    Problem Statement: 
        Write a function which takes a decimal number (an  int) as a parameter and returns a string of 0’s and 
        1’s representing the same number in binary (base 2).  For example, pass the function an  int  variable 
        and with a value of 100.  Your function should return the string "1100100".

    Algorithm / Plan:
    1. Gather neccesary inputs from the user and continue this process until -1 is entered.
    2. Call a function that passes the input value from the user.
    3. In the function define variables for output and remainder storage.
    4. Find the modulus of the input and 2 and store into the remainder.
    5. Set the input to itself divided by 2.
    6. Convert the remainder to string and add it to the begining of the output string.
    7. Repeat until the input = 0.
    8. Pass this back to the main function and output to the user.

*/
#include <iostream>
using namespace std;

string decimal_to_binary(int input);

int main() {

    string final_value = "";
    int input = 0;

    while(input != -1) {
        //Gather variable from user
        cout << "Please enter decimal number (Whole positive number): ";
        cin >> input;
        
        if (input >= 0) {
            //Gather the passed Variable and output to user
            final_value = decimal_to_binary(input);
            cout << "Number in Binary: " << final_value << endl << endl;
        } else {
            cout << "Program ended." << endl;
        }
        
        }
    

    return 0;
}

string decimal_to_binary(int passed_input) {
    string output = "";
    int input_remainder = 2;

    //Loop and divide by 2 and extract the remainder and insert at front of string
    while(passed_input != 0) {
        input_remainder = passed_input % 2;
        passed_input /= 2;
        output.insert(0, to_string(input_remainder));
    }

    if(output.empty()) {
        output = "0";
    }


    return output;

}
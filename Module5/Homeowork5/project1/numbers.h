/* numbers.h - Numbers to Words
    Name: Liam Walker
    Module: 5
    Project: 1
    Problem Statement: Design a class named  Numbers  that can be used to translate whole dollar amounts in the range of 0 through 9999 
                       into an English description of the number.  For example, the number 713 would be translated into the string 
                       "seven hundred thirteen", and 8203 would be translated into "eight thousand two hundred three".

    Purpose: To practice using classes, constructors, and member functions in C++.
   

*/

#ifndef NUMBERS_H
#define NUMBERS_H

#include <cstring>
#include <iostream>

using namespace std;



class Numbers {
    
    private:
        static const string kUnder20[];
        static const string kTens[];
        static const string kHundred;
        static const string kThousands[];
        int number;

    public:
        Numbers(int number);
        void print();
        
        
};

// Static member variable definitions
const string Numbers::kUnder20[] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                                    "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

const string Numbers::kTens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
const string Numbers::kHundred = "Hundred";
const string Numbers::kThousands[] = { "", "Thousand", "Million", "Billion" };


// Constructor
Numbers::Numbers(int passed_number) {
    if (passed_number > 0 || passed_number < 9999) {
       this->number = passed_number;
    } 
    
}

// Print function to convert number to words
void Numbers::print() {
    if (number == 0) {
        cout << kUnder20[0] << endl;
        return;
    }
    int num = number;
    string result = "";
    // Handle thousands place adds the word "thousand" if the number is greater than 1000
    int thousand = num / 1000;
    if (thousand > 0) {
        result += kUnder20[thousand] + " " + kThousands[1] + " ";
        num %= 1000;
    }
    // Handle hundreds place adds the word "hundred" if the number is greater than 100
    int hundred = num / 100;
    if (hundred > 0) {
        result += kUnder20[hundred] + " " + kHundred + " ";
        num %= 100;
    }
    // Handle tens and ones place adds the word for the tens place if the number is greater than 20 and then adds the word for the ones place if the number is greater than 0
    if (num >= 20) {
        int ten = num / 10;
        result += kTens[ten] + " ";
        num %= 10;
    }
    // Handle numbers under 20 adds the word for the number if it is greater than 0
    if (num > 0) {
        result += kUnder20[num] + " ";
    }

    cout << result << endl;
}

#endif
/* Money.cpp - Represents money using separate variables for dollars and cents
 * Author:     Chris Merrill
 * Module:     6
 * Project:    Lab #2
 * Description:
 *   Uses two variables, one (long long) representing dollars and a
 *      second (an int) representing cents.  The cents should always be
 *      between 0 and 99.
 */

#include <string>
#include <iostream>
using namespace std;

class Money {

    private:
        // Instance variables
        long long dollars = 0;
        int cents = 0;                  // should be between 0 and 99

    public:
        // constructor takes a String representing dollars and cents and
        // divides into a "dollars" and "cents" variables
        Money(string amount) {
            int index = amount.find(".");
            if (index == -1) {                   // no decimal point
                dollars = stol(amount);
                cents = 0;
           } else {
               if (index == 0) {                 // no dollars
                   amount = "0" + amount;
                   index++;
               }
               dollars = stol(amount.substr(0, index));
               cents = stoi(amount.substr(index + 1, amount.length()));
           }
           cout << "In the constructor of $" << amount << endl;        }

        // Copy constructor (prints a message)
        Money(const Money &amount) {
            dollars = amount.dollars;
            cents = amount.cents;
            cout << "In the " << amount << " copy constructor" << endl;
        }

        // Move constructor (prints a message)
        Money(Money &&amount) {
            dollars = amount.dollars;
            cents = amount.cents;
            cout << "In the " << amount << " move constructor" << endl;
        }

        // Assignment operator
        Money operator=(const Money &amount) {
            dollars = amount.dollars;
            cents = amount.cents;
            cout << "In the " << amount << " assignment operator" << endl;
            return *this;
        }

        // Returns the money amount as a string
        string getAmount() const {
            string zero = (cents <= 9 ? "0" : "");
            return "$" + to_string(dollars) + "." + zero + to_string(cents);
        }

        Money operator+(const Money &right) const {
            long long sumDollars = dollars + right.dollars;
            int sumCents = cents + right.cents;
            if (sumCents > 99) {
                sumDollars++;
                sumCents -= 100;
            }
            return Money(to_string(sumDollars) + "." + (sumCents <= 9 ? "0" : "") + to_string(sumCents));
        }

        bool operator>=(const Money &right) const {
            return right.dollars * 100 + right.cents <= dollars * 100 + cents;
        }

        friend ostream & operator<<(ostream &out, const Money &amount) {
            out << amount.getAmount();
            return out;
        }

};


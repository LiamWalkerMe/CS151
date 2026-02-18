#include <iostream>
using namespace std;

int main() {
    bool pi_has_six_digits = false;

    double current_pi = 4;
    double previous_pi = 0;
    double denomenator = 3;
    bool is_positive = false;

    while (!pi_has_six_digits) {
        if(is_positive) {
            cout << "Adding 1/" << denomenator << endl;
            current_pi = current_pi + (4/denomenator);
            is_positive = false;
        } else {
            cout << "Subtracting 1/" << denomenator << endl;
            current_pi = current_pi - (4/denomenator);
            is_positive = true;
        }
        denomenator += 2;


        if (int(current_pi * 1000000) == int(previous_pi * 1000000)) {
            pi_has_six_digits = true;
        }
        previous_pi = current_pi;
    }

    cout << "Pi accuracy to six digits is: " << current_pi;

}
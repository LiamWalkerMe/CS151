/* project1.cpp - use a vector to store numbers 
Author: Liam Walker 
Module: 1
Project: Homework 1
*/

#include <iostream>
#include <vector>
using namespace std;

/* used for testing, prints out the whole vector
void printVector(vector<int> passed_vector) {
    for(int i = 0; i < passed_vector.size(); i++) {
        cout << passed_vector[i] << ", ";
    }
    cout << endl;

}
*/


int main() {
    // Initialize Variables
    vector<int> numbers;
    vector<int>::iterator it;
    int position = 0;

    //Random seed
    srand(1);
    
    //Start Vector off with a random number
    int num = 0;
    
    //Loop through 29 times as the first number is already in the vector
    for(int i = 0; i < 30; i++) {
        num = (rand() % 10) + 1;

        //Iterate through numbers vector to find position
        for(int j = 0; j < numbers.size(); j++) {
        
        
            //check if random number should go between two numbers in the vector
            if(num > numbers[j]) {
                position = 0;
                break;
            } else if(num <= numbers[j] && num > numbers[j+1]) {
                position = j + 1;
                break;
            } else {
                position = numbers.size();
            }
            
        }

        //Insert number
        it = numbers.begin() + position;
        numbers.insert(it, num);


    }
    
    while(numbers.size() > 0) {
        int last_element = numbers.back();
        numbers.pop_back();
        cout << last_element << ", ";
    }
    
    return 0;
}


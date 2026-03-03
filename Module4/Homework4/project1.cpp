/* project1.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 4
    Project: 1
    Problem Statement: 

    Algorithm / Plan:
    1. Define an array and struct for stones
    2. Set up random number generator
    3. Loop through the number of stones to randomly assign a stone a position in the array and count the number
        of attempts it takes to get a stone in a non-occupied spot
    4. Output this in an organized manner
    5. Resort the array by the slot char stored in the array, making sure that the slot number gets stored in the
        struct so it can be accesses after sorting
    6. Outout the new array in an organized manner

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include <algorithm>

using namespace std;

// Define Stone struct ot contain slot, slot number, and number of attempts. Default constructor
struct Stone {
    char slot;
    int slot_num;
    int num_attempts;

    Stone(char passed_slot, int passed_slot_num, int passed_num_attempts) {
        slot = passed_slot;
        slot_num = passed_slot_num;
        num_attempts = passed_num_attempts;
    }

};


int main() {
    // Define variables

    const int kNumberOfStones = 10;
    char stone_letter[] = {'A','B','C','D','E','F','G','H','I','J'};

    unique_ptr<Stone> slots[10];
    int attempts = 0;
    int index = 0;

    
    // Define random number gen
    random_device seed;
    default_random_engine gen(seed());
    uniform_int_distribution<int> slot(0, kNumberOfStones - 1);  


    // Loop through the stone array and insert a stone in a random number from 0 - 9 location in the array. 
    for (int i = 0; i < kNumberOfStones; i++) {
        
        do {
            index = slot(gen);
            attempts++;

        } while (slots[index]);

        unique_ptr<Stone> new_stone(new Stone(stone_letter[i], index,  attempts));  
        slots[index] = move(new_stone);
        
        attempts = 0;
    

    }

    // Headers
    cout << "Report by Slot" << endl;
    cout << setw(4) << "Slot " << setw(5) << "Stone " << setw(8) << "Attempts" << endl;
    cout << setw(4) << "---- " << setw(5) << "----- " << setw(8) << "--------" << endl;

    int total_attempts = 0;

    // Calculate and pring slot, stone, number of attemps, and total attempts
    for (int i = 0; i < kNumberOfStones; i++) {
        
        cout << right << setw(4) << i + 1 << " "
             << setw(5) << slots[i]->slot << " "
             << setw(8) << slots[i]->num_attempts << endl;
        total_attempts += slots[i]->num_attempts;
    }

    cout << endl << "Total Attempts: " << total_attempts << endl << endl;

    // Resort the stones position by Stone char
    for (int i = 0; i < kNumberOfStones - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < kNumberOfStones; j++) {
            // Compare the stone letters 
            if (slots[j]->slot < slots[min_idx]->slot) {
                min_idx = j;
            }
        }
        // Swap the unique_ptrs 
        swap(slots[i], slots[min_idx]);
    }


    // Headers
    cout << "Report by Stone" << endl;
    cout << setw(4) << "Stone " << setw(5) << "Slot " << setw(8) << "Attempts" << endl;
    cout << setw(5) << "----- " << setw(4) << "---- " << setw(8) << "--------" << endl;

    total_attempts = 0;

    // Print the now sorted stones by stone char
    for (int i = 0; i < kNumberOfStones; i++) {
        
        cout << setw(5) << slots[i]->slot << " " 
             << right << setw(4) << slots[i]->slot_num + 1 << " "
             << setw(8) << slots[i]->num_attempts << endl;

        total_attempts += slots[i]->num_attempts;
    }

    cout << endl << "Total Attempts: " << total_attempts << endl << endl;



    return 0;
}
/* project.cpp - Recursive Search
    Name: Liam Walker
    Module: 11
    Project: 2
    Problem Statement: Write a program that prompts the user for the size of an integer array, then prompts the user to enter the integers to fill the array. Finally, prompt the user for a target integer and use a recursive function to search for the target integer in the array, returning true if found and false if not found.

    Algorithm / Plan:
    1. Prompt the user for the size of an integer array and read the input.
    2. Create an integer array of the specified size.
    3. Prompt the user to enter integers to fill the array and read the input.
    4. Prompt the user for a target integer and read the input.
    5. Call a recursive function to search for the target integer in the array.
    6. Implement the recursive function to search for the target integer in the array, returning true if found and false if not found.

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
using namespace std;

bool recursiveSearch(int arr[], int size, int target);

int main() {
    
    // Prompt the user for the size of an integer array and read the input
    cout << "Please enter the size of the integer array: ";
    int size;
    cin >> size;

    int numbers[size];

    // Prompt the user to enter integers to fill the array and read the input
    for (int i = 0; i < size; i++) {
        cout << "Please enter integer " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Prompt the user for a target integer and read the input
    cout << "Please enter the integer to search for: ";
    int target;
    cin >> target;

    // Call a recursive function to search for the target integer in the array
    if (recursiveSearch(numbers, size, target)) {
        cout << "The integer " << target << " was found in the array." << endl;
    } else {
        cout << "The integer " << target << " was not found in the array." << endl;
    }

    return 0;
}

bool recursiveSearch(int arr[], int size, int target) {
    // Base Case: If size is 0, the target is not found
    if (size == 0) {
        return false;
    }

    // Check the last element of the array
    if (arr[size - 1] == target) {
        return true;
    }

    // Recursive Case: Search the rest of the array
    return recursiveSearch(arr, size - 1, target);
}
/* project.cpp - PROGRAM_DESCRIPTION
    Name: Liam Walker
    Module: 
    Project: 
    Problem Statement:

    Algorithm / Plan:
    1.
    2.
    3.
    4.
    5.
    6.
    7.
    8.
    9.
    10.

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include "LinkedList.h"
using namespace std;

int main() {
    
    LinkedList<int> list;

    cout << "\nEmpty list: ";
    list.display();

    cout << endl;

    list.addLast(6);
    list.addLast(34);
    list.addLast(12);
    list.addLast(56);
    list.addLast(23);
    list.addLast(12);

    while (true) {
        cout << "\nCurrent list: ";
        list.display();
        cout << endl;
        cout << "\n=== LinkedList Menu ===" << endl;
        cout << "1. Remove first element" << endl;
        cout << "2. Remove at index" << endl;
        cout << "3. Set element at index" << endl;
        cout << "4. Check For Element" << endl;
        cout << "5. Display Last Element" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        
        int choice;
        cin >> choice;
        // Remove First Element
        if (choice == 1) {
            int removed = list.removeAt(0);
            cout << "Removed: " << removed << endl;
        }
        // Remove at index
        else if (choice == 2) {
            cout << "Enter index to remove: ";
            int index;
            cin >> index;

            // Remove the element at the specified index and display the removed value, try and catch any exceptions thrown by invalid index
            try {
                int removed = list.removeAt(index);
                cout << "Removed at index " << index << ": " << removed << endl;
            } catch (...) {
                cout << "Invalid index: " << index << " (out of range)" << endl;
            }
        }
        // Set element at index
        else if (choice == 3) {
            cout << "Enter index: ";
            int index;
            cin >> index;
            cout << "Enter new value: ";
            int value;
            cin >> value;
            // Set the value at the specified index and display the old value try and catch any exceptions thrown by invalid index
            try {
                int old = list.set(index, value);
                cout << "Set index " << index << " to " << value;
                cout << " (old value was: " << old << ")" << endl;
            } catch (...) {
                cout << "Invalid index: " << index << " (out of range)" << endl;
            }
        }
        // Check for element
        else if (choice == 4) {
            cout << "Enter Value to Check For: ";
            int value;
            cin >> value;

            // Check if the list contains the value and display appropriate message, try and catch any exceptions thrown by invalid index
            try {
                if(list.contains(value)) {
                    cout << "Element with value: " << value << ": Found" << endl;
                } else {
                    cout << "Element with value: " << value << ": Not found" << endl;
                }
        
            } catch (...) {
                cout << "Invalid index: " << index << " (out of range)" << endl;
            }
        }
        // Display last index of element

        else if (choice == 5) {
            cout << "Enter value to find last index of: ";
            int value;
            cin >> value;
            int index = list.lastIndexOf(value);
            // Display the last index of the value if found, or an appropriate message if not found
            if (index != -1) {
                cout << "Last index of " << value << ": " << index << endl;
            } else {
                cout << "Value " << value << " not found in the list." << endl;
            }
        }
        
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
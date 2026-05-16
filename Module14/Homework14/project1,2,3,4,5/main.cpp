/* project1.cpp - Simple LinkedList Class
    Name: Liam Walker
    Module: 14
    Project: 1
    Problem Statement: Using an appropriate definition of  ListNode,  design a simple linked list class with only two member functions and a default constructor

    Algorithm / Plan:
    1. Define a ListNode struct with an integer value and a pointer to the next node.
    2. Define a LinkedList class with a private member variable head (pointer to the first node).
    3. Implement the default constructor to initialize head to nullptr.
    4. Implement the add function to insert new numbers at the front of the list.
    5. Implement the isMember function to check if a value is in the list.
    6. Implement the print function to display the list values.
    7. Implement the reverse function to reverse the list.
    8. Implement the search function to find the position of a value in the list.
    9. Implement the insert function to insert a value at a specific position.

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
using namespace std;

#include "LinkedList.cpp"

int main() {
    // Create a LinkedList object using the default constructor
    LinkedList list;

    // IS MEMBER FUNCTION

    // Add nodes 7, 8, and 9
    list.add(7);
    list.add(8);
    list.add(9);

    cout << "List: ";
    list.print(); // Should show (9 8 7) or similar order depending on
    
    cout << endl;
    cout << "Check isMember for values 9, 7, and 5:" << endl;

    // Test isMember function
    cout << "Is 9 in the list? ";
    if (list.isMember(9)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    cout << "Is 7 in the list? ";
    if (list.isMember(7)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    cout << "Is 5 in the list? ";
    if (list.isMember(5)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    cout << endl;
    

    // PRINT FUNCTION

    // Print an empty list and the current list using the print function
    LinkedList emptyList;

    cout << "Testing print function:" << endl;
    
    cout << "Current list: ";
    list.print(); // Should show (9 8 7) or similar order depending on add implementation

    cout << "Empty list: ";
    emptyList.print(); // Should show (empty)

    cout << endl;

    cout << "Testing reverse function:" << endl;

    // REVERSE FUNCTION

    // Reverse the list and print it again
    list.reverse();
    cout << "Reversed list: ";
    list.print(); // Should show (7 8 9) or similar order depending on
    
    cout << "Reverse again: ";
    list.reverse();
    list.print(); // Should show (9 8 7) again

    cout << endl;

    // SEARCH FUNCTION

    cout << "Testing search function:" << endl;

    cout << "Position of 8 in the list: " << list.search(8) << endl; // Should show 1
    cout << "Position of 5 in the list: " << list.search(5) << endl; // Should show -1 (not found)

    cout << endl;

    // INSERT FUNCTION

    cout << "Testing insert function:" << endl;

    cout << "Testing Member Insertion by Position" << endl;

    // 1. Test inserting into an empty list / head
    cout << "Inserting 20 at position 0 (Empty List):" << endl;
    list.insert(20, 0);
    list.print(); 
    
    // Add a few more items to set up the rest of the tests
    list.add(10); 

    // 2. Test inserting at the end (pos >= length)
    cout << "\nInserting 40 at position 5 (End of list):" << endl;
    list.insert(40, 5);
    list.print(); 

    // 3. Test inserting in the middle
    cout << "\nInserting 30 at position 2 (Middle of list):" << endl;
    list.insert(30, 2);
    list.print(); 

    return 0;   

    cout << endl;

    return 0;
}
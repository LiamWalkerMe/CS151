/* Sorter.cpp - Use two stacks to sort an array
 * Author:     Chris Merrill
 * Module:     15
 * Project:    Homework
 * Problem statement:  Use 2 stacks (only push, pop, and top) to sort an
 *      array of numbers in either ascending, descending, or random order
 * Algorithm: In main create arrays of ints in different sequences and sizes.
 *  1. Prompt for the sequence the original array should be in (random, ascending,
 *     or descending) order.
 *  2. Prompt for the size of the array - should be between 10 and 1,000
 *  3. Build an array of ints in the specified sequence and of the specified size
 *  4. Call the "sorter" function which takes any array of ints, then use two
 *     stacks from the STL to return the array in ascending order.
 *     a. stacks can be of any type which supports push, pop, and peek
 *     b. Create a counter for the number of times a "push" is used on either stack
 *     c. Load the array into one of the LinkedLists, then use as stack #1
 *     d. While stack #1 is not empty:
 *         i.   Pop the top number on that stack into a temporary variable
 *         ii.  Pop all numbers from stack #2 which are less than or equal to the
 *              temporary variable back onto stack #1, incrementing the count
 *              of pushes each time
 *         iii. Push the number in the temporary variable onto stack #2
 *         iv.  Increment the counter for the total number of pushes used
 *    e. When the loop finishes, load stack #2 back into the original array
 *    f. Return the count of pushes
 */

#include <stack>
#include <random>
#include <iomanip>
#include <iostream>
using namespace std ;

// prototypes
int sorter(int[], int) ;
string addCommas(long long) ;

int main() {

    // Ask user to determine the initial sequence of the array to be sorted and
    // size of the array
    int sequence = 0, size = 0 ;
    do {
        cout << "Which original order (1-random, 2-ascending, 3-descending): " ;
        cin >> sequence ;
        if (sequence < 1 || sequence > 3) {
            cout << "   Please enter a number between 1 and 3" << endl ;
        }
    } while (sequence < 1 || sequence > 3) ;

    do {
        cout << "How big to make the array (10 - 1,000): " ;
        cin >> size ;
        if (size < 10 || size > 1000) {
            cout << "  Please enter a number between 10 and 1,000" << endl ;
        }
    } while (size < 10 || size > 1000) ;

    // Create an array of random numbers, an array of increasing numbers, or an array
    // of decreasing numbers
    int array[size];
    string description = "" ;                     // random, ascending, or descending

    // Determine the original sequence of the elements in the array
    switch (sequence) {
        case 1:  description = "random" ;
                 break ;

        case 2:  description = "ascending" ;
                 break ;

        default: description = "descending" ;
    }

    random_device seed ;
    default_random_engine gen(seed()) ;
    uniform_int_distribution<int> dist(1, size) ;

    // Initialize the array based on the original sequence whhich the user specified
    for (int i = 0 ; i < size ; i++) {
        switch(sequence) {

            case 1:  array[i] = dist(gen) ;        // random order
                     break ;

            case 2:  array[i] = i + 1 ;            // ascending order
                     break ;

            default: array[i] = size - i ;         // descending order
        }
    }

    // Print the array before sorting
    cout << "\nThe array before sorting: \n" ;
    for (int i = 0 ; i < size ; i++) {
        cout << setw(4) << array[i] ;
        if ((i + 1) % 25 == 0) {
            cout << endl ;          // Put 25 numbers on a line
        }
    }

    // Call the function which uses two stacks to sort
    int pushes = sorter(array, size) ;

    // Print the total number of "pushes" used followed by the sorted array
    cout << "\nTotal of " << addCommas(pushes) << " pushes for "
         << addCommas(size) << " " << description << " numbers \n" << endl ;
    for (int i = 0 ; i < size ; i++) {
        cout << setw(4) << array[i] ;
        if ((i + 1) % 25 == 0) {
           cout << endl ;
        }
    }
}

// Use 2 stacks to sort the array and return the total number of pushes
// used in the sort.
int sorter(int arr[], int size) {

    int count = 0 ;        // number of pushes used during the sorting

    /* ******************************* START ADDING CODE HERE *****************************/

    //                  Code for this Assignment code goes between these lines

    /* ************************************************************************************/
    stack<int> stack1 ;    // the array to be sorted  
    stack<int> stack2 ;    // the sorted array when finished  

    // Load the contents of the array onto stack1
    for (int i = 0 ; i < size ; i++) {
        stack1.push(arr[i]) ;
    }
    // Loop until the elements in stack1 have been  
    // inserted into stack2 (in sorted order)
    while (! stack1.empty()) {  
        // Pop and store the top element from stack1 into a temporary  
        // variable, then move all elements in stack2 onto stack1
        // which are less than the temporary variable
        int temp = stack1.top() ;
        stack1.pop() ;
        while (! stack2.empty() && temp > stack2.top()) {  
            stack1.push(stack2.top()) ;
            stack2.pop() ;
            count++ ;
            
            // Push the temporary element onto stack2.  
            stack2.push(temp) ;  
            count++ ;
        }
        


    // Reload the numbers from stack2 onto the array  
    for (int i = 0 ; i < size ; i++) {
        arr[i] = stack2.top() ;
        stack2.pop() ;
    }
 
    }

    return count ;     // total number of pushes used
}

// Return a string representing a large number with commas added
string addCommas(long long number) {

    string as_string = to_string(number) ;    // number to convert
    string result = "" ;                      // result to return

    // If present, remove negative sign
    bool is_negative = false ;
    if (as_string[0] == '-') {
        is_negative = true ;
        as_string = as_string.substr(1) ;     // remove negative sign
    }

    // Iterate through the string from right to left, adding commas
    // after every 3 digits
    int position = 0 ;
    for (int i = as_string.length() - 1 ; i >= 0 ; i--) {
        result.insert(0, 1, as_string[i]) ;
        position++ ;
        if (position % 3 == 0 && i != 0)
            {result.insert(0, 1, ',') ;  }     // add the comma
    }

    // Add a negative sign if original number was negative
    if (is_negative)
        { result = "-" + result ; }

    return result ;
}

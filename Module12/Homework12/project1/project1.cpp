/* project.cpp - Sorting Algorithm Comparison
    Name: Liam Walker
    Module: 12
    Project: 1
    Problem Statement: Design an abstract class named  AbstractSort  which can be used to analyze the number of comparisons performed by a sorting algorithm.  The class should have a member function  compare  that is capable of comparing two array elements, and a means of keeping track of the number of comparisons performed.

    Algorithm / Plan:
    1. Create an abstract class called AbstractSort with a pure virtual function sort and a compare function.
    2. Create a derived class called BubbleSort that inherits from AbstractSort and implements the
         sort function using the bubble sort algorithm.
    3. In the main function, create two arrays of integers and fill them with random numbers.
    4. Print the original arrays.
    5. Create an instance of the BubbleSort class and use it to sort both arrays
    6. Print the sorted arrays.
    7. Count the number of comparisons made during the sorting process and print the count for

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
using namespace std;

class AbstractSort {

    public:
        int compare(int arr[ ], int k, int m);
        virtual void sort(int arr[ ], int size ) = 0; // pure virtual function
    


};

// My favorite sorting algorithm!
class BubbleSort : public AbstractSort {
    public:
    int comparisons;
    
    void sort(int arr[ ], int size ) override {
        comparisons = 0; // Initialize comparisons counter
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                comparisons++; // Increment comparisons counter for each comparison
                if (compare(arr, j, j + 1) > 0) {
                    swap(arr[j], arr[j + 1]);
                    comparisons++; // Increment comparisons counter for each swap
                }
                }
            }
        }
        
};

// Compare function to compare two elements in the array
int AbstractSort::compare(int arr[ ], int k, int m) {
    if (arr[k] < arr[m]) {
        return -1;
    } else if (arr[k] > arr[m]) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    // Define random number gen
    random_device seed;
    default_random_engine gen(seed());
    uniform_int_distribution<int> slot(-10, 100);  


    // Define arrays to be sorted
    int arr[20] = {5, 2, 9, 1, 5, 6, 7, 3, 4, 8, 10, 12, 11, 15, 14, 13, 20, 19, 18, 17};
    int arr2[15] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4};

    // Fill arrays with random numbers

    for (int i = 0; i < 20; i++) {
        arr[i] = slot(gen);
    }

    for (int i = 0; i < 15; i++) {
        arr2[i] = slot(gen);
    }

    cout << endl;

    // ARRAY 1

    // Print the original array
    cout << "Array before sorting: " << endl;
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    // Sort the array and print the sorted array
    cout << "Array after sorting: " << endl;
    BubbleSort bubble_sort;
    bubble_sort.sort(arr, 20);
    
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    cout << bubble_sort.comparisons << " comparisons were made to sort 20 elements." << endl << endl;


    // ARRAY 2

    cout << "Array2 before sorting: " << endl;
    for (int i = 0; i < 15; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl << endl;


    cout << "Array2 after sorting: " << endl;
    bubble_sort.sort(arr2, 15);
    
    for (int i = 0; i < 15; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl << endl;

    cout << bubble_sort.comparisons << " comparisons were made to sort 15 elements." << endl;
    
    cout << endl;







    return 0;
}



/* project2.cpp - Dynamic Allocation of Two-Dimensional Arrays
    Name: Liam Walker
    Module: 3
    Project: 2
    Problem Statement: The Objective: Develop a program to demonstrate proficiency in dynamic memory management and the conceptual mapping 
        of data across different array structures. You will explore two distinct methods for handling 2D data: mathematical indexing on a contiguous 
        1D array and the creation of a true "array-of-arrays."

    Algorithm / Plan:
    1. Create a one-dimensional dynamic array of 20  ints  and fill with random numbers from 1 to 99.
    2. Print the contents of the array, a grand total of the numbers in the array, and the average of those numbers to 2 decimal places.
    3.Using the first technique described above for creating two-dimensional dynamic arrays, treat the one-dimensional array above as a 
        two-dimensional array with 4 rows each with 5 numbers  (height = 4, width = 5).  Use the index into the first array (0 to 19) to calculate 
        the associated row (0 to 3) and column (0 to 4)  in a two-dimensional array.  On separate lines, print the  contents of each row followed by 
        total and average of the numbers in that row.
    4. Calculate a grand total of the numbers in the array using this technique of accessing elements in a 2-dimensional array (it should be the 
        same as the grand total of all 20 numbers from step 2).  Print this total aligned under the totals for each row.
    5. Calculate the average of the four row averages.  It should be the same as the average of all 20 numbers from step 2.  Print this total aligned 
        under the averages for each row.
    6. Create a two-dimensional "array-of-arrays" using the second technique described above.  The array should have 4 rows each with 5 columns.
    7. Copy the numbers from the array used in steps 1-4 into the new array, where each element in the new two-dimensional array corresponds to 
        the same element in the first two-dimensional array.  You may use any technique you wish to copy the elements from one array to the other.
    8. Similar to what you did in steps 3, 4, and 5, on separate lines print the contents of each row in the new array followed by the total and 
        average of those numbers.  They should match the numbers printed in steps 4 and 5 above for each row.
    9. Deallocate the arrays created in steps 1 and 6.

*/
#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
using namespace std;

int main() {

    // Random number generation
    mt19937 gen(10);
    uniform_int_distribution<> distrib(1, 99);

    // ONE DIMENSIONAL ARRAY

    // Define variable
    int const kArray_Size = 20;
    int* single_array = new int[kArray_Size];
    double total = 0;

    //Loop through arrray and assign random number, add to running total
    for (int i = 0; i < 20; i++) {
        int random_number = distrib(gen);
        single_array[i] = random_number;
        total += random_number;
    }

    // Display One Dimensional Array
    
    cout << endl << "Original array of 20 numbers:" << endl << "[";
    
    for (int i = 0; i < kArray_Size; i++) {
        if (i == kArray_Size - 1) {
            cout << single_array[i];
        } else {
            cout << single_array[i] << ", ";
        }
        
    }
    cout << "]" << endl;
    
    cout << setfill('=') << setw(78) << "" << endl;
    cout << setfill(' ') << "Total: " << total
         << "  Average: " << fixed << setprecision(2) << total/kArray_Size << endl;
    cout << setfill(' ') << endl << endl;

    int const kHeight = 4;
    int const kWidth = 5;

    // TWO DIMENSIONAL ARRAY (Technique 1)

    cout << "Using that array as a 4 x 5 array: " << endl;

    
    //Treat the 1st array like a two dimensional array and display
    double row_total = 0;
    total = 0;
    for (int row = 0; row < kHeight; row++) {
        row_total = 0;

        cout << left << setw(3) << "Row " << row << ": ";

        for(int col = 0; col < kWidth; col++) {
            int index = (row * kWidth) + col;
            int row_value = single_array[index];
            row_total += row_value;
            cout << right << setw(2) << row_value << "  ";

            
        }
        // Calculate and display row totals and averages
        total += row_total;
        cout << setw(6) << left << "Total: " << (int)row_total ;
        cout << setw(6) << left << "  Average: " << fixed << row_total/kWidth << endl;
        

    }

    // Calculate and display totals and averages
    cout << setfill('=') << setw(53) << "" << setfill(' ') << endl;
    cout << setw(21) << " " 
         << setw(12) << "Grand Total: " << (int)total
         << "  Average: " << total/kArray_Size;

    cout << endl << endl;

    // TWO DIMENSIONAL ARRAY (Technique 2)

    cout << "Using an array-of-arrays: " << endl;

    //Set up array of arrays
    int **array_of_arrays = new int * [kHeight] ;
    for (int row = 0; row < kHeight; row++) {
        array_of_arrays[row] = new int[kWidth];
    }

    //Copy 1st array to new array
    for (int row = 0; row < kHeight; row++) {
        
        for(int col = 0; col < kWidth; col++) {
            int index = (row * kWidth) + col;
            array_of_arrays[row][col] = single_array[index];
            
        }

    }

    // Loop through array and grab the associated variables
    row_total = 0;
    total = 0;
    for (int row = 0; row < kHeight; row++) {
        row_total = 0;

        cout << left << setw(3) << "Row " << row << ": ";

        for(int col = 0; col < kWidth; col++) {
            int row_value = array_of_arrays[row][col];
            row_total += row_value;
            cout << right << setw(2) << row_value << "  ";

            
        }
        // Calculate and display row totals and averages
        total += row_total;
        cout << setw(6) << left << "Total: " << (int)row_total ;
        cout << setw(6) << left << "  Average: " << fixed << row_total/kWidth << endl;
        

    }

    // Calculate and display totals and averages
    cout << setfill('=') << setw(53) << "" << setfill(' ') << endl;
    cout << setw(21) << " " 
         << setw(12) << "Grand Total: " << (int)total
         << "  Average: " << total/kArray_Size;

    cout << endl << endl;




    return 0;
}
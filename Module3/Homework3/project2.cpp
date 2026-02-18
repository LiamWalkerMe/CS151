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

    int const kArray_Size = 20;

    mt19937 gen(10);
    uniform_int_distribution<> distrib(1, 99);
    
    int one_dimension[kArray_Size];

    double total = 0;

    for (int i = 0; i < 20; i++) {
        int random_number = distrib(gen);
        one_dimension[i] = random_number;
        total += random_number;
    }
    
    cout << "One Dimensional Array:" << endl;
    
    for (int i = 0; i < kArray_Size; i++) {
        cout << "Position " << i + 1 << ": " << one_dimension[i] << endl;
    }
    
    cout << setfill('=') << setw(10) << "" << endl;
    cout << setfill(' ') << "Total: " << total << endl;
    cout << "Average: " << fixed << setprecision(2) << total/kArray_Size << endl;
    cout << setfill('=') << setw(10) << "" << setfill(' ') << endl;

    int const kHeight = 4;
    int const kWidth = 5;

    int *two_dimensional = new int[kHeight * kWidth];
    for (int row = 0; row < kHeight; row++) {
        for(int col = 0; col < kWidth; col++) {
            int index = (row * kWidth) + col;
            two_dimensional[index] = one_dimension[index];
        }
    }


    int row_total = 0;
    for (int row = 0; row < kHeight; row++) {
        row_total = 0;
        cout << "Row: ";

        for(int col = 0; col < kWidth; col++) {
            int index = (row * kWidth) + col;
            int row_value = two_dimensional[index];
            row_total += row_value;
            cout << setw(4) << row_value;

            
        }
        cout << "   Row Total: " << row_total << endl;

    }



    

    


    return 0;
}
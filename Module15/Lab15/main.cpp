#include <iostream>
#include <string>
#include "SetLinkedList.h" // Ensure this matches your header file name

using namespace std ;
// Template function to run and print the required tests for each case
template <typename T>
void runTests(Set<T> A, Set<T> B) {
    // 1. Calculate the operations
    Set<T> intersection_set = A.setIntersect(B); // Assuming your base class has intersection()
    Set<T> minus_set = A.minus(B);
    Set<T> union_of_both = minus_set.setUnion(intersection_set); // Assuming your base class has set_union() or union()
    
    // 2. Print the contents of the 5 sets
    cout << "Set A: ";
    A.display(); // Assuming your base class has a display method
    
    cout << "Set B: ";
    B.display();
    
    cout << "A n B: ";
    intersection_set.display();
    
    cout << "A - B: ";
    minus_set.display();
    
    cout << "(A - B) U (A n B): ";
    union_of_both.display();
    
    // 3. Demonstrate equality: A should equal ((A - B) U (A n B))
    cout << "Equal?: " << (A.equals(union_of_both) ? "yes" : "no") << endl;
    
    // 4. Print the size of set A
    cout << "Set A has " << A.size() << " elements" << endl;
}

int main() {

    // TEST CASE 1 & 2 (Using string)

    Set<string> setA_str;
    Set<string> setB_str;

    // Test Case 1
    cout << "Test case #1:" << endl;
    setA_str.insert("C");
    setA_str.insert("G");
    setA_str.insert("E");
    setA_str.insert("A");

    setB_str.insert("E");
    setB_str.insert("C");
    setB_str.insert("F");

    runTests(setA_str, setB_str);
    cout << "\n-----------------------------------------\n\n";

    // Clear sets before Test Case 2
    setA_str.clear();
    setB_str.clear();

    // Test Case 2
    cout << "Test case #2:" << endl;
    setA_str.insert("Carlos");
    setA_str.insert("John");
    setA_str.insert("Alice");

    setB_str.insert("John");
    setB_str.insert("Henry");
    setB_str.insert("Maria");

    runTests(setA_str, setB_str);
    cout << "\n-----------------------------------------\n\n";


    // TEST CASE 3 & 4 (Using int)

    Set<int> setA_int;
    Set<int> setB_int;

    // Test Case 3
    cout << "Test case #3:" << endl;
    setA_int.insert(15);
    setA_int.insert(11);
    setA_int.insert(13);

    setB_int.insert(11);
    setB_int.insert(13);
    setB_int.insert(15);
    setB_int.insert(17);
    setB_int.insert(19);

    runTests(setA_int, setB_int);
    cout << "\n-----------------------------------------\n\n";

    // Clear sets before Test Case 4
    setA_int.clear();
    setB_int.clear();

    // Test Case 4
    cout << "Test case #4:" << endl;
    setA_int.insert(9);
    // setB_int is left empty intentionally { }

    runTests(setA_int, setB_int);
    cout << endl;

    return 0;
}
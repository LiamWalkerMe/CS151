/* SimpleVector.h - Simple Vector with added functionality
 * Author:     <your name>
 * Module:     13
 * Project:    Homework #2
 */

#pragma once

#include <iostream>
using namespace std ;

template <class T>
class SimpleVector {

    protected:
        T *aptr ;
        int size = 0 ;                        // number of elements in vector
        int capacity = 0 ;                    // size of underlying array

    public:
        SimpleVector(int = 0) ;               // Constructor
        SimpleVector(const SimpleVector &) ;  // Copy constructor
        ~SimpleVector() ;                     // Destructor

        int getCapacity() const
            { return capacity ; }
        int getSize() const
            { return size ; }
        
        void push_back(T value) ;             // Add element to back
        T pop_back() ;                        // Remove element from back
} ;

//*************************************************************
//         Constructor for EnhancedSimpleVector class         *
// Sets the size of the array and allocates memory for it.    *
//*************************************************************
template <class T>
SimpleVector<T>::SimpleVector(int new_capacity) {

    size = 0 ;
    capacity = new_capacity ;
    aptr = new T [capacity] ;

    // Empty the contents of the array
    for (int count = 0 ; count < capacity ; count++) {
        *(aptr + count) = T() ;
    }
}

//**************************************************
//     Copy Constructor for SimpleVector class     *
//**************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {

    capacity = obj.capacity ;
    aptr = new T [capacity] ;
    for(int count = 0 ; count < capacity ; count++) {
        *(aptr + count) = *(obj.aptr + count) ;
    }
}

//***********************************************
//     Destructor for SimpleVector class        *
//***********************************************
template <class T>
SimpleVector<T>::~SimpleVector() {

    if (capacity > 0) {
        delete [] aptr ;
    }
}

//***********************************************
//     push_back for SimpleVector class         *
//***********************************************
template <class T>
void SimpleVector<T>::push_back(T value) {

    if (size >= capacity)
        throw overflow_error("Vector is full") ;
    aptr[size++] = value ;
}

//***********************************************
//     pop_back for SimpleVector class          *
//***********************************************
template <class T>
T SimpleVector<T>::pop_back() {

    if (size == 0)
        throw underflow_error("Vector is empty") ;
    return aptr[--size] ;
}

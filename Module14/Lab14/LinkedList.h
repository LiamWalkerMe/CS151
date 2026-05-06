/* LinkedList.h - Generic class allowing representation of a linked list
 * Author:     <your name here>
 * Module:     14
 * Project:    Lab
 * Problem statement:  This file contains the definition for a generic
 *    Node class and a generic LinkedList class.  Enhance an generic LinkedList.h
 *    class with several functions to make the class more usable.
 *
 *    Functions should throw a run-time exception if there would be confusion between
 *    what is returned (successful) and something couldn't be returned.
 *
 * Algorithm:
 *    Classes already included are  Node<T> and LinkedList<T>
 *    Functions already given are:  full constructor, addFirst, addLast, add,
 *        getFirst, getLast, get, indexOf, getSize, isEmpty, removeFirst,
 *        removeLast, and clear
 *
 *    Functions to be created in this lab are:
 *        display, remove, removeAt, lastIndexOf, contains, and set
 */

#pragma once

#include <iostream>
#include <stdexcept>                          // catch run-time errors
using namespace std;

/******************************
 *                            *
 *  Template for Node class   *
 *                            *
 ******************************/
template<typename T>
class Node {
    public:
        T data;                // value or object stored in the node
        Node<T> *next;         // pointer to the next node

    // No-arg constructor
    Node() {
        next = nullptr;
    }

    // Constructor with one parameter
    Node(T myData) {
        this->data = myData;   // stores value in node's data field
        next = nullptr;
    }
};

/*****************************************
 *                                       *
 *   Template for the LinkedList class   *
 *                                       *
 *****************************************/
template<typename T>
class LinkedList {

    private:
        Node<T> *head, *tail;         // pointers to first and last nodes
        int size;                       // number of nodes in this list

    public:

        // Prototypes of functions already present
        LinkedList();                           // constructor

        void addFirst(T myData);                // add an element to the list
        void addLast(T myData);
        void add(int index, T myData);

        T getFirst() const;                     // accessors
        T getLast() const;
        T get(int index) const;
        int indexOf(T myData) const;
        int getSize() const;
        bool isEmpty() const;

        T removeFirst();  // remove an element or clear
        T removeLast();
        void clear();

        // Function prototypes to be provided in this lab
        bool contains(T myData) const;
        int lastIndexOf(T myData) const;
        bool remove(T myData);
        T removeAt(int index);
        T set(int index, T myData);
        void display() const;
};

/************************************
*                                   *
*     Function implementations      *
*                                   *
*************************************/

// Constructor
template<typename T>
LinkedList<T>::LinkedList() {                    // An empty list
    head = tail = nullptr;
    size = 0;
}

// Add node to beginning of the list
template<typename T>
void LinkedList<T>::addFirst(T myData) {
    Node<T> *newNode = new Node<T>(myData);    // Create new node and ptr
    newNode->next = head;                      // Assign value of head ptr to next ptr of new node
    head = newNode;                            // Set head to point at new node
    size++;                                    // increment size of LinkedList

    if (!tail)
        tail = head;                           // set tail ptr to new node if list was empty
}

// Add node to the end of the list
template<typename T>
void LinkedList<T>::addLast(T myData) {
    if (!tail) {                      // list is empty
        head = tail = new Node<T>(myData);     // point head and tail to new node
    } else {
        tail->next = new Node<T>(myData);      // create new node
        tail = tail->next;                     // set tail ptr to new node
    }
    size++;
}

// Add node at specific index
template<typename T>
void LinkedList<T>::add(int index, T myData) {
    if (index == 0) {                           // add node at beginning of list
        addFirst(myData);
    } else if (index >= size) {                 // add node at end of list
        addLast(myData);
    } else {                                    // insert this element between two nodes
        Node<T> *current = head;              // loop to node before this one
        for (int i = 1; i < index; i++)
            current = current->next;
        Node<T> *temp = current->next;        // one after this one
        current->next = new Node<T>(myData);
        (current->next)->next = temp;
        size++;
    }
}

// Return data from first node, if present
template<typename T>
T LinkedList<T>::getFirst() const {
    if (size == 0) {
        throw runtime_error("No nodes in the list"); // no nodes in the list
    }
    return head->data;                     //retrieve value in first node
}

// Get data from last node
template<typename T>
T LinkedList<T>::getLast() const {                    // no nodes in the list
    if (size == 0) {
        throw runtime_error("No nodes in the list"); // retrieve value in last node
    }
    return tail->data;
}

// Get node at the specific index
template<typename T>
T LinkedList<T>::get(int index) const {
    if (index < 0 || index > size - 1)
        throw runtime_error("Index out of range.");

    Node<T> *ptr = head;                    // walk list
    for (int i = 0; i < index; i++)
        ptr = ptr->next;                    // point to next node
    return ptr->data;                       // get value if found
}

// Get the index of first occurence a specific data node
template<typename T>
int LinkedList<T>::indexOf(T myData) const {
    Node<T> *ptr = head;
    for (int i = 0; i < size; i++) {
        if (ptr->data == myData)            // walk list to find value
            return i;
        ptr = ptr->next;
    }
    return -1;                             // return -1 if value not found
}

// Get the number of nodes in the list (number added - number removed)
template<typename T>
int LinkedList<T>::getSize() const {
    return size;
}

// Remove first node from list
template<typename T>
T LinkedList<T>::removeFirst() {
    if (size == 0) {
        throw runtime_error("No nodes in the list");
    }
    Node<T> *front = head;            // create new ptr pointing to same place as head
    head = head->next;                // point to the next object beyond the first
    size--;
    if (!head) {
        tail = nullptr;
    }
    T myData = front->data;
    delete front;                     // delete node that was at the front
    return myData;                    // may or may not use this value
}

// Remove last node from the list
template<typename T>
T LinkedList<T>::removeLast() {
    if (size == 0) {
        throw runtime_error("No nodes in the list");
    }
    if (size == 1) {
        return removeFirst();              // may or may not use this value
    }
    Node<T> *ptr = head;                   // start at the beginning of the list
    for (int i = 0; i < size - 2; i++)  { // walk list moving ptr to end
        ptr = ptr->next;
    }
    Node<T> *temp = tail;
    tail = ptr;
    tail->next = nullptr;
    size--;
    T myData = temp->data;
    delete temp;
    return myData;
}

// Clear the list - takes time but frees up memory
template<typename T>
void LinkedList<T>::clear() {
    while (head) {                     // if still a node in list
        Node<T> *temp = head;         // set temp ptr to what head points at
        head = head->next;            // point head at next node
        delete temp;                  // delete the node temp is pointing to
    }
    head = tail = nullptr;            // the empty list
    size = 0;
}

// See if the list is empty
template<typename T>
bool LinkedList<T>::isEmpty() const {
    return !head;                     // no nodes in list
}

/**********************************************************
*                                                         *
*      Functions to be provided by you in this lab        *
*                                                         *
**********************************************************/

// Display the contents of the list on the console
template<typename T>
void LinkedList<T>::display() const {
    if (isEmpty()) {
        cout << "(null)" << endl;
        return;
    }
    Node<T> *ptr = head;
    while (ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Remove a node with a specific data element
// Return false if element not found, true if removed
template<typename T>
bool LinkedList<T>::remove(T myData) {
    if (isEmpty()) {
        return false;
    }
    
    // Check if it's the head node
    if (head->data == myData) {
        Node<T> *temp = head;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        size--;
        delete temp;
        return true;
    }
    
    // Search for the node to remove
    Node<T> *ptr = head;
    while (ptr->next) {
        if (ptr->next->data == myData) {
            Node<T> *temp = ptr->next;
            ptr->next = temp->next;
            if (!temp->next) {
                tail = ptr;
            }
            size--;
            delete temp;
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

// Remove a node at a specific index or position
// Return the element removed if successful
// Throw exception if invalid location
template<typename T>
T LinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= size) {
        throw runtime_error("Index out of range.");
    }
    
    if (index == 0) {
        return removeFirst();
    }
    
    Node<T> *ptr = head;
    for (int i = 0; i < index - 1; i++) {
        ptr = ptr->next;
    }
    
    Node<T> *temp = ptr->next;
    ptr->next = temp->next;
    if (!temp->next) {
        tail = ptr;
    }
    size--;
    T myData = temp->data;
    delete temp;
    return myData;
}

// Find the last index of a specific data element

template<typename T>
int LinkedList<T>::lastIndexOf(T myData) const {
    int lastIndex = -1; // Return -1 if element not found
    Node<T> *ptr = head;
    for (int i = 0; i < size; i++) {
        if (ptr->data == myData) {
            lastIndex = i;
        }
        ptr = ptr->next;
    }
    return lastIndex;
}

// Determine if the list contains a specific data element

template<typename T>
bool LinkedList<T>::contains(T myData) const {
    return indexOf(myData) != -1; // Return true if found, false if not found
}

// Modify or set the data value of a node at a specific index
// Return the old element at that index if replaced, or T() if unsuccessful
template<typename T>
T LinkedList<T>::set(int index, T myData) {
    if (index < 0 || index >= size) {
        throw runtime_error("Index out of range.");
    }
    
    Node<T> *ptr = head;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    
    T oldData = ptr->data;
    ptr->data = myData;
    return oldData;
}
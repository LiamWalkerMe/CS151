/* LinkedList.cpp - Simple LinkedList Class
    Name: Liam Walker
    Module: 14
    Project: 1
    Problem Statement:

    Algorithm / Plan:
    1. Define the LinkedList class and ListNode struct in LinkedList.h.


*/
#include "LinkedList.h"
#include <iostream>

using namespace std;


// Definition of ListNode is assumed to be in the header; if not, a local definition
LinkedList::LinkedList()
    : head(nullptr) {
}

// Implementing LinkedList member functions.
void LinkedList::add(int new_number) {
    // insert at front
    head = new ListNode(new_number, head);
}



// Returns true if value is in the list, false otherwise
bool LinkedList::isMember(int value) const {
    ListNode* cur = head;
    while (cur) {
        if (cur->value == value) return true;
        cur = cur->next;
    }
    return false;
}

// Prints the list values in order, separated by spaces
void LinkedList::print() {
    ListNode* cur = head;
    if (!cur) {
        cout << "(empty)" << endl;
        return;
    }
    while (cur) {
        cout << cur->value;
        if (cur->next) cout << " ";
        cur = cur->next;
    }
    cout << endl;
}

// Reverses the list by rearranging node pointers without creating or destroying nodes.
void LinkedList::reverse() {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Returns the position of a number on the list (0-indexed), or -1 if not found
int LinkedList::search(double number) {
    ListNode* cur = head;
    int position = 0;
    while (cur) {
        if (cur->value == number) return position;
        cur = cur->next;
        position++;
    }
    return -1;
}


// Inserts a new element at the specified position.
void LinkedList::insert(double new_number, int pos) {
    if (pos <= 0 || !head) {
        head = new ListNode(new_number, head);
        return;
    }
    ListNode* prev = head;
    int index = 1;
    while (prev->next && index < pos) {
        prev = prev->next;
        index++;
    }
    prev->next = new ListNode(new_number, prev->next);
}
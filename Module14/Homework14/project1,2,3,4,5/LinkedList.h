/* LinkedList.h - Simple LinkedList Class
    Name: Liam Walker
    Module: 14
    Project: 1
    Problem Statement:

    Algorithm / Plan:
    1. Define the LinkedList class and ListNode struct in LinkedList.h.


*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    
    ListNode(int val, ListNode* nxt = nullptr) : value(val), next(nxt) {}
};

class LinkedList {
private:
    ListNode* head;
    
public:
    LinkedList();
    void add(int new_number);
    bool isMember(int value) const;
    void print();
    void reverse(); 
    int search(double number); 
    void insert(double new_number, int pos);

};

#endif


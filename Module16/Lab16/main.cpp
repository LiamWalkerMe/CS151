/* main.cpp - Binary Tree Test Program
    Name: Liam Walker
    Module: 16
    Project: 1
    Problem Statement:

    Algorithm / Plan:
    1. Create 5 different binary trees with different values and structures to test the getHeight and getSize functions.

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include "EBinaryTree.cpp"
using namespace std;

int main() {
    // Tree 1: Names entered in alphabetic order
    EBinaryTree<string> tree1;
    vector<string> alphabetic = {"Albert", "Barbara", "Cesar", "Dexter", "Eduardo", "Frank", "Georgio", "Heather"};
    cout << "Tree 1 (Alphabetic Order):" << endl;
    for (const auto& name : alphabetic) {
        tree1.insert(name);
    }
    cout << "Height: " << tree1.getHeight() << ", Diameter: " << tree1.getDiameter() << ", Size: " << tree1.getSize() << endl << endl;
    cout << "Tree 1 Preorder:" << endl;
    tree1.showPreorder();
    cout << "Tree 1 Inorder:" << endl;
    tree1.showInorder();
    cout << "Tree 1 Postorder:" << endl;
    tree1.showPostorder();
    cout << endl;

    // Tree 2: Names entered in reverse alphabetic order
    EBinaryTree<string> tree2;
    vector<string> reverse = {"Heather", "Georgio", "Frank", "Eduardo", "Dexter", "Cesar", "Barbara", "Albert"};
    cout << "Tree 2 (Reverse Alphabetic Order):" << endl;
    for (const auto& name : reverse) {
        tree2.insert(name);
    }
    cout << "Height: " << tree2.getHeight() << ", Diameter: " << tree2.getDiameter() << ", Size: " << tree2.getSize() << endl << endl;
    cout << "Tree 2 Preorder:" << endl;
    tree2.showPreorder();
    cout << "Tree 2 Inorder:" << endl;
    tree2.showInorder();
    cout << "Tree 2 Postorder:" << endl;
    tree2.showPostorder();
    cout << endl;

    // Tree 3: Names entered level-by-level to create balanced structure
    EBinaryTree<string> tree3;
    vector<string> levelOrder = {"Cesar", "Barbara", "Eduardo", "Albert", "Dexter", "Georgio", "Frank", "Heather"};
    cout << "Tree 3 (Level-by-Level Order):" << endl;
    for (const auto& name : levelOrder) {
        tree3.insert(name);
    }
    cout << "Height: " << tree3.getHeight() << ", Diameter: " << tree3.getDiameter() << ", Size: " << tree3.getSize() << endl << endl;
    cout << "Tree 3 Preorder:" << endl;
    tree3.showPreorder();
    cout << "Tree 3 Inorder:" << endl;
    tree3.showInorder();
    cout << "Tree 3 Postorder:" << endl;
    tree3.showPostorder();
    cout << endl;

    // Tree 4: Height 5, Diameter 8 (13 nodes, diameter through root)
    EBinaryTree<int> tree4;
    // Generates exactly Size: 13, Height: 5, Diameter: 8
    vector<int> tree4_values = {
        9,             // Level 1 (Root)
        7, 11,         // Level 2
        5, 8, 10, 12,  // Level 3
        3, 6, 13,      // Level 4
        2, 4,          // Level 5
        1              // Level 6
    };
    cout << "Tree 4 (Height 5, Diameter 8, Size 13, Through Root):" << endl;
    for (const auto& val : tree4_values) {
        tree4.insert(val);
    }
    cout << "Height: " << tree4.getHeight() << ", Diameter: " << tree4.getDiameter() << ", Size: " << tree4.getSize() << endl << endl;
    cout << "Tree 4 Preorder:" << endl;
    tree4.showPreorder();
    cout << "Tree 4 Inorder:" << endl;
    tree4.showInorder();
    cout << "Tree 4 Postorder:" << endl;
    tree4.showPostorder();
    cout << endl;

    // Tree 5: Height 5, Diameter 8 (15 nodes, diameter not through root)
    EBinaryTree<int> tree5;
    // Generates exactly Size: 15, Height: 5, Diameter: 8
    vector<int> tree5_values = {
        13,                // Level 1 (Root)
        7, 14,             // Level 2
        5, 9, 15,          // Level 3
        3, 6, 8, 10,       // Level 4
        2, 4, 11,          // Level 5
        1, 12              // Level 6
    };
    cout << "Tree 5 (Height 5, Diameter 8, Size 15, Not Through Root):" << endl;
    for (const auto& val : tree5_values) {
        tree5.insert(val);
    }
    cout << "Height: " << tree5.getHeight() << ", Diameter: " << tree5.getDiameter() << ", Size: " << tree5.getSize() << endl << endl;
    cout << "Tree 5 Preorder:" << endl;
    tree5.showPreorder();
    cout << "Tree 5 Inorder:" << endl;
    tree5.showInorder();
    cout << "Tree 5 Postorder:" << endl;
    tree5.showPostorder();
    cout << endl;
    
    return 0;
}
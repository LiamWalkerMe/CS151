/* EBinaryTree.cpp - Extend the functions in the BinaryTree class
 * Author:     Chris Merrill
 * Module:     16
 * Project:    Modified version of demonstration BinaryTree class for this Lab
 * Description:  renamed the BinaryTree class to EBinaryTree and moved contents
 *      of BinaryTree.cpp into this file
 *
 * Public Functions:
 *     - constructor(value)
 *     - destructor()                     - calls destroySubtree
 *     - bool search(value)               - no recursive version
 *     - bool insert(value)               - calls recursive version
 *     - bool remove(value)               - calls recursive version
 *     - void showPreorder()              - calls recursive version
 *     - void showInorder()               - calls recursive version
 *     - void showPostorder()             - calls recursive version
 *     - vector<T> toVector()             - cheap replacement for an iterator
 *     - showTree(bool)                   - entry into recursive drawTree()
 *
 * Functions defined outside of the class (private unless otherwise specified)
 *     - destroySubtree(Node *)           - used by the destructor
 *     - insert(Node *, value)            - recursive function to insert a node
 *     - search(value)                    - non-recursive function (public)
 *     - remove(Node *, value)            - recursive function to remove a node
 *     - makeDelete(Node *)               - remove the node
 *     - displayPreorder(Node *)          - displays the subtree in preorder sequence
 *     - displayInorder(Node *)           - displays the subtree in inorder sequence
 *     - displayPostorder(Node *)         - displays the subtree in postorder sequence
 *     - toVector(Node *)                 - builds a vector of values in the tree  *    - drawTree(Node *, int, int, bool) - recursive function to display a tree
 */

#include <iostream>
#include <vector>
using namespace std ;

template<class T>
class EBinaryTree {

private:

    // The TreeNode struct is used to build the tree.  It is internal to the EBinaryTree
    // class and therefore does not need to be specified as <T> when used to define
    // functions
    struct TreeNode {
        T value ;
        TreeNode *left ;
        TreeNode *right ;
        TreeNode(T value, TreeNode *left = nullptr, TreeNode *right = nullptr) {
            this->value = value ;
            this->left = left ;
            this->right = right ;
        }
    } ;

    TreeNode *root ;              // Pointer to the root of the tree

    // Remove default copy constructor and assignment operator
    EBinaryTree(const EBinaryTree &) = delete ;
    EBinaryTree & operator=(const EBinaryTree &) = delete ;

    // Various helper member functions.
    bool insert(TreeNode *&, T) ;
    void destroySubtree(TreeNode *) ;
    void remove(TreeNode *&, T) ;
    void makeDeletion(TreeNode *&) ;
    void displayInorder(TreeNode *) const ;
    void displayPreorder(TreeNode *) const ;
    void displayPostorder(TreeNode *) const ;
    void toVector(vector<T> *, TreeNode *) const ;
    void drawTree(TreeNode *, int, int, bool) const ;
    int getHeight(TreeNode *) const ;   // a private version 
    int getSize(TreeNode *) const ;  // private version  
    int getDiameter(TreeNode *) const ;   // private version

public:
    EBinaryTree() { root = nullptr ; }                     // Constructor
    ~EBinaryTree() { destroySubtree(root) ; }              // Destructor
    bool insert(T data) { return insert(root, data) ; }    // Add an item
    bool search(T) const ;
    void remove(T num) { remove(root, num) ; }             // Delete an item
    void showInorder(void) const {
        if (!root) {
            cout << "(empty)" ;
        } else {
            displayInorder(root) ;
        }
        cout << endl ;
    }
    void showPreorder() const {
        if (!root) {
            cout << "(empty)" ;
        } else {
            displayPreorder(root) ;
        }
        cout << endl ;
    }
    void showPostorder() const {
        if (!root) {
            cout << "(empty)" ;
        } else {
            displayPostorder(root) ;
        }
        cout << endl ;
    }
    vector<T> * toVector() const {
        vector<T> *vect = new vector<T>() ;
        toVector(vect, root) ;
        return vect ;
    }
    void showTree(bool show_nulls) const {
        drawTree(root, 1, 1, show_nulls) ;
    }
    int getHeight( ) const ;            // a public version
    int getSize() const ;            // public version  
    int getDiameter() const ;             // public version 

} ;


//**************************************************
// destroySubTree is called by the destructor. It  *
// deletes all nodes in the tree.                  *
//                                                 *
// It works by recursively going down to each leaf *
// (first left, then right subtrees), and deleting *
// from the bottom up.                             *
//**************************************************
template<typename T>
void EBinaryTree<T>::destroySubtree(TreeNode *tree) {

    if (!tree) {
        return ;
    }
    destroySubtree(tree->left) ;
    destroySubtree(tree->right) ;

    // Delete the node at the root.
    delete tree ;
}

//**************************************************
// Insert inserts a value into a given subtree of  *
// the main binary search tree.                    *
//**************************************************
template<typename T>
bool EBinaryTree<T>::insert(TreeNode * &tree, T data) {
    // If the tree is empty, create a new node and make it
    // the root of the tree.
    if (!tree) {
        tree = new TreeNode(data) ;
        return true ;
    }

    // If the value is already in tree: return.
    if (tree->value == data) {
        return false ;
    }

    // The tree is not empty: insert the new node into the
    // left or right subtree.
    if (data < tree->value)
        return insert(tree->left, data) ;
    return insert(tree->right, data) ;
}

//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//                                                  *
// Recursion is NOT used in this function, since    *
// it just traverses the appropriate subtrees (not  *
// the entire tree) and stops once value is found   *
//***************************************************
template<typename T>
bool EBinaryTree<T>::search(T data) const {

    TreeNode *tree = root ;                // start at the top

    while (tree) {
        if (tree->value == data)
            return true ;
        if (data < tree->value) {   // look only at appropriate subtree
            tree = tree->left ;
        } else {
            tree = tree->right ;
        }
    }
    return false ;
}

//********************************************
// Deletes the node in the given tree that   *
// has a value member the same as the        *
// specified value.                          *
//********************************************
template<typename T>
void EBinaryTree<T>::remove(TreeNode *&tree, T data) {

    if (!tree) { return ; }                // not in the original tree

    if (data < tree->value) {               // look in left subtree
        remove(tree->left, data) ;
    } else if (data > tree->value)  {       // look in right subtree
        remove(tree->right, data) ;
    } else {
        makeDeletion(tree) ;                // found it -- delete this node
    }
}

//***********************************************************
// makeDeletion takes a reference to a tree whose root      *
// is to be deleted. If the tree has a single child, the    *
// the tree is replaced by the single child after the       *
// removal of its root node. If the tree has two children   *
// the left subtree of the deleted node is attached at      *
// an appropriate point in the right subtree, and then      *
// the right subtree replaces the original tree.            *
//***********************************************************
template<typename T>
void EBinaryTree<T>::makeDeletion(TreeNode *&tree) {

    // Used to hold node that will be deleted.
    TreeNode *nodeToDelete = tree ;

    // Used to locate the  point where the left subtree is attached.
    TreeNode *attachPoint ;

    if (!tree->right) {
        // Replace tree with its left subtree.
        tree = tree->left ;
    } else if (!tree->left)    {
        // Replace tree with its right subtree.
        tree = tree->right ;
   } else {
        //The node has two children, so move to right subtree.
        attachPoint = tree->right ;

        // Locate the smallest node in the right subtree
        // by moving as far to the left as possible.
        while (attachPoint->left) {
            attachPoint = attachPoint->left ;
        }

        // Attach the left subtree of the original tree
        // as the left subtree of the smallest node
        // in the right subtree.
        attachPoint->left = tree->left ;

        // Replace the original tree with its right subtree.
        tree = tree->right ;
    }

    // Delete root of original tree
    delete nodeToDelete ;
}

//***************************************************
// Displays the values stored in inorder sequence.  *
//***************************************************
template<typename T>
void EBinaryTree<T>::displayInorder(TreeNode *tree) const {
    if (tree) {
        displayInorder(tree->left) ;
        cout << tree->value << "  " ;
        displayInorder(tree->right) ;
    }
}

//****************************************************
// Displays the values stored in preorder sequence. *
//****************************************************
template<typename T>
void EBinaryTree<T>::displayPreorder(TreeNode *tree) const {
    if (tree) {
        cout << tree->value << "  " ;
        displayPreorder(tree->left) ;
        displayPreorder(tree->right) ;
    }
}
//****************************************************
// Displays the values stored in postorder sequence. *
//****************************************************
template<typename T>
void EBinaryTree<T>::displayPostorder(TreeNode *tree) const {
    if (tree) {
        displayPostorder(tree->left) ;
        displayPostorder(tree->right) ;
        cout << tree->value << "  " ;
    }
}

//*************************************************
// Returns a vector of values in the binary tree  *
// using inorder sequence.                        *
//*************************************************
template<typename T>
void EBinaryTree<T>::toVector(vector<T> *vect, TreeNode *tree) const {
    if (tree) {
        toVector(vect, tree->left) ;
        vect->push_back(tree->value) ;
        toVector(vect, tree->right) ;
    }
}

//************************************************************
// Recursive method using an inorder traversal to print a    *
// binary tree on its side                                   *
//                                                           *
// Parameters are the local node to print its data value     *
// and its subtree, the level at this node (root = depth 1)  *
// and a bool to show the tree down to the nulls             *                          *
//************************************************************
template<typename T>
void EBinaryTree<T>::drawTree(TreeNode *tree, int level, int leftRight,
                             bool showNulls) const {

    // Graphics characters to draw the tree
    char rightTree = 218, leftTree = 192, horizontal = 196 ;

    // Don't print when ignoring nulls
    if (!tree && !showNulls) {
        return ;
    }

    // Recursively add the right subtree to the ArrayList
    if (tree) {
        drawTree(tree->right, level + 1, 0, showNulls) ;
    }

    // Print the data for this node (or "(null)" if it's a null).
    // Indent 5 spaces for each level, and identify if this is
    // the root of the tree (level 1)
    if (level == 1) {
        cout << "      root: " ;
    } else {
        cout << "   "  ;
        for (int i = 1 ; i <= level ; i++) {
            cout << "     " ;
        }
        cout << (leftRight == 1 ? leftTree : rightTree) ;
        cout << horizontal << horizontal << horizontal ;
    }
    if (tree) {
        cout << " " << tree->value << endl ;
    } else {
        cout << "(null)" << endl ;
    }

    // Recursively print the left subtree
    if (tree) {
        drawTree(tree->left, level + 1, 1, showNulls) ;
    }
}

// NEWLY CREATED FUNCTIONS

//**************************************************
// getHeight calls the private version.             *
//                                                  *
// It works by recursively going down to each leaf  *
// (first left, then right subtrees), and returns   *
// 1 + the maximum height of both subtrees.         *
//**************************************************
template<typename T>
int EBinaryTree<T>::getHeight( ) const {
    return getHeight(root) ;
}  

//**************************************************
// getHeight calculates the height of the tree.   *
//                                                 *
// It works by recursively going down to each leaf *
// (first left, then right subtrees), and returns *
// 1 + the maximum height of both subtrees.       *
//**************************************************
template <typename E>
int EBinaryTree<E>::getHeight(TreeNode *tree) const {
    // Base case: If the node is null, its height contribution is 0
    if (tree == nullptr) {
        return 0;
    }
    
    // Base case: Return 0 when the node is a leaf
    if (tree->left == nullptr && tree->right == nullptr) {
        return 0;
    }
    
    // Recursive case: 1 + the height of the deeper subtree
    return 1 + max(getHeight(tree->left), getHeight(tree->right));
}



//**************************************************
// getSize calls the private version.             *
//                                                  *
// It works by recursively going down to each leaf  *
// (first left, then right subtrees), and returns   *
// the total number of nodes in the tree.         *
//**************************************************
template<typename T>
int EBinaryTree<T>::getSize() const {
    return getSize(root) ;
}


//**************************************************
// getSize calculates the size of the tree.   *
//                                                 *
// It works by recursively going down to each leaf *
// (first left, then right subtrees), and returns *
// the total number of nodes in the tree.       *
//**************************************************
template <typename E>
int EBinaryTree<E>::getSize(TreeNode *tree) const {
    // Base case: The size of a null tree is 0
    if (tree == nullptr) {
        return 0;
    }
    
    // Recursive case: 1 (the current node) + sizes of left and right subtrees
    return 1 + getSize(tree->left) + getSize(tree->right);
}

//**************************************************
// getDiameter calls the private version.             *
//                                                     *
// It works by recursively going down to each leaf *
// (first left, then right subtrees), and returns *
// the maximum distance between any two nodes.    *
//**************************************************
template<typename T>
int EBinaryTree<T>::getDiameter() const {
    return getDiameter(root) ;
}

//**************************************************
// getDiameter calculates the diameter of the tree.   *
//                                                     *
// It works by recursively going down to each leaf *
// (first left, then right subtrees), and returns *
// the maximum distance between any two nodes.    *
//**************************************************
template<typename T>
int EBinaryTree<T>::getDiameter(TreeNode *tree) const {
    // If at a "null" node, then stop recursion
    if (tree == nullptr) return 0 ;

    // Calculate the height of the left and right subtrees
    int left_height = getHeight(tree->left) ;
    int right_height = getHeight(tree->right) ;

    // Calculate the diameter of the left and right subtrees  
    int left_diameter = getDiameter(tree->left) ;
    int right_diameter = getDiameter(tree->right) ;  

    // Find the maximum of the left subtree diameter, the
    // right subtree diameter, and the longest path which
    // goes up to or through the root of this (sub)tree
    int edges = (tree->left != nullptr) + (tree->right != nullptr) ;  
    return max(left_height + right_height + edges, 
        max(left_diameter, right_diameter)) ;
}
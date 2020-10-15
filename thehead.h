#ifndef THEHEAD_H_INCLUDED
#define THEHEAD_H_INCLUDED


#include <iostream>
#include <math.h>
#include <iomanip>
#include <limits>


using namespace std;

// function initialization

int options(); // function for asking user for option


  struct node // structure for the node holding a tree number
    {
        int number;
        node* left = nullptr;
        node* right = nullptr;
    };


class BST // class for the binary search tree
{

private:
    node* root=nullptr; // root holding everything


public:

    void insertNode(int number); // function for inserting node
    bool findNode(int key);// function for finding node  and return a boolean
    void deleteNode(int key); //function for deleting node from tree
    int longestnode(node*); // function for returning the height of tree
    void addToTree(node *, int *, int); // function for adding numbers from node to dynamic array for use later
    void printTreeFormat(); // function for  printing the tree out
    void printNode(node*); // help function to sort order to print numbers in tree
    void sortedOrder(); // printing out numbers in tree from highest to lowest
    double adder(node*); //function for adding
    void findCost(); //function for printing out the largest cost


};




#endif // THEHEAD_H_INCLUDED

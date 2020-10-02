/*
Name: michael Ameteku
Date: October 7th 2020
Project: Assignment 3

pseudo:  First, you implement a Binary Search Tree (BST) using a Linked List.
Then, you provide the following functions in your program. Please write a main.cpp to only include
calling functions.
Please design your program with input/output menu so that a user can easily test and use your
program

1. (10 points) Write a function that searches a node in a BST.
2. (10 points) Write a function that inserts a new node into a BST.
3. (20 points) Write a function that deletes an existing node in a BST.
4. (20 points) Write a function that display all nodes in a tree format.
For example:
 50
 / \
 20 80
 / \ / \
 10 30 60 90
5. (20 points) Write a function that prints out the keys for a BST in sorted order from highest to
lowest.
6. (20 points) The cost of a path in a tree is sum of the keys of the nodes participating in that path.
Write a function that returns the cost of the most expensive path from the root to a leaf node in
a BST
*/
#include "heading.h"
#include <iostream>


using namespace std;

int main()

{
    int number;
    BST theTree;
    int option;

    option = options();
    switch(option)
    {
    case 1:
        cout<<"Enter number you are looking for"<<endl;
        cin>>number;
        theTree.findNode(number);
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    }


    return 0;
}

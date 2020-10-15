/*
Name: michael Ameteku
Date: October 7th 2020
Project: Assignment 3

pseudo:  First, you implement a Binary Search Tree (BST) using a Linked List.
Then, you provide the following functions in your program. Please write a main.cpp to only include
calling functions.
Please design your program with input/output menu so that a user can easily test and use your
program

1. (10 points) Write a function that searches a node in a BST. - done
2. (10 points) Write a function that inserts a new node into a BST. - done
3. (20 points) Write a function that deletes an existing node in a BST. done
4. (20 points) Write a function that display all nodes in a tree format.
    -print a lot of space and the root
    --pass
5. (20 points) Write a function that prints out the keys for a BST in sorted order from highest to lowest. done
    go right until you reach the highest node,
    (
    print that node
    if node has a left node, go there
        check for right, pint if there
        check fr left
    return to node before that
    return to other nodes.
    repeat
    base case: if left nodeptr and right ptr are null



6. (20 points) The cost of a path in a tree is sum of the keys of the nodes participating in that path.
Write a function that returns the cost of the most expensive path from the root to a leaf node in -done
a BST
*/

#include <iostream>
#include "thehead.h"

using namespace std;

int main()

{
    //variable declarations
    int lowestlevel;
    int number;
    BST theTree;
    int choice;
    bool found;
    bool endIt=false;



    // reiterating options
    while(!endIt)
    {
        //asking for user input
        choice = options();
        switch(choice)
        {
        case 1:
            cout<<"Enter number you are looking for"<<endl;
            cin>>number;
            found= theTree.findNode(number); // checking if value i sin tree
            if(found)
                cout<<"found\n";
            else
                cout<<"not found!\n";
            break;
        case 2:
            cout<<"Enter number you want to insert"<<endl;
            cin>>number;
            theTree.insertNode(number); //adding number to tree

            break;
        case 3:
            cout<<"Enter number you want to delete"<<endl;
            cin>>number;
            theTree.deleteNode(number); //removing number from tree
            break;
        case 4:
            theTree.sortedOrder(); // printing out tree from ascending to descending
            break;
        case 5:
            theTree.printTreeFormat(); // printing in the tree format
            break;
        case 6:
            theTree.findCost(); // find expensive path
            break;
        case 7:
            endIt = true;
            break;
        }
    }


    return 0;
}





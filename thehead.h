#ifndef THEHEAD_H_INCLUDED
#define THEHEAD_H_INCLUDED


#include <iostream>
#include <math.h>


using namespace std;


int options();
bool numvalid(int number);

  struct node
    {
        int number;
        node* left = nullptr;
        node* right = nullptr;
    };


class BST
{

private:
    node* root=nullptr;


public:

    void insertNode(int number);
    bool findNode(int key);
    void deleteNode(int key);
    int longestnode(node*);
    void printTreeFormat();
    void printNode(node*);
    void sortedOrder();
    double adder(node*);

    void findCost();


};




#endif // THEHEAD_H_INCLUDED

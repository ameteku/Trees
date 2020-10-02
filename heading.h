#ifndef HEADING_H_INCLUDED
#define HEADING_H_INCLUDED
#include <iostream>


using namespace std;

class BST
{
private:
    struct node
    {
        int number;
        node* left = nullptr;
        node* right = nullptr;
    };

    node *headptr= nullptr;

public:
    void insertNode(int number, node * headptr);
    node* searchNode(int key);
    void findNode(int key);
    void deleteNode(int key);
    void printTreeFormat();
    void sortedOrder();
    void findCost();


};

int options();
bool numvalid(int number);

#endif // HEADING_H_INCLUDED

#include "heading.h"

int options()
{
    int num;
    cout<<"1.Search a node in BST\n"
        <<"2.Insert a new node into BST.\n"
        <<"3.Delete an existing node in BST.\n"
        <<"4.Display all nodes in a tree format.\n"
        <<"5.prints out the keys for a BST in sorted order\n"
        <<"6. cost of the most expensive path\n";
    do
    {
        cin>>num
       /* if(cin.fail() || num<1 || num>6)
        {
            cout<<"Wrong  input";
            cin.clear;
            cin.
        }*/

    }
    while(cin.fail());
    return num;
}

BST::node*searchNode(int key)
{
    node *searcher= headptr;
    while(searcher!=nullptr)
    {
        if(searcher->number==key)
        {
            return headptr;
        }
        else if(searcher->number>=key)
        {
            searcher = searcher->left;
        }
        else if(searcher->number<key)
        {
            searcher=searcher->right;
        }
    }
    return searcher;
}

BST:: bool insertNode(int numbers)
{
   node* pos = searchNode(numbers);
   node newnum= newnum->number = numbers;
   pos = newnum;
}

BST::void findNode(int key)
{
    node *searcher= headptr;
    while(searcher!=nullptr)
    {
        if(searcher->number==key)
        {
            cout<<"found\n";
            return;
        }
        else if(searcher->number>=key)
        {
            searcher = searcher->left;
        }
        else if(searcher->number<key)
        {
            searcher=searcher->right;
        }
    }
    if(searcher==nullptr)
    {
        cout<<"Not found!\n";
        return;
    }





}

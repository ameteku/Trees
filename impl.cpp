#include "thehead.h"

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
        cin>>num;
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


void BST:: insertNode(int numbers)
{

    //if its the first number, set headptr to it
    if(root==nullptr)
    {
        root = new node;
        root->number = numbers;
        cout<<root->number<<endl;
        return;
    }
    else
    {
        node *pos = root;
        node * initialpos = pos;
        while(pos!= nullptr)
        {

             if(pos->number>numbers)
            {
                initialpos = pos;
                pos = pos->left;
            }
            else if(pos->number<numbers)
            {
                initialpos = pos;
                pos = pos->right;
            }
            else // if number is equal to number in tree in current postion
            {
                cout<<"number in tree already\n";
                return;
            }

        }

        if( initialpos->number>numbers)
            {
                initialpos->left=new node;
                initialpos->left->number=numbers;
                return;
            }
            else if( initialpos->number<numbers)
            {
                initialpos->right = new node;
                initialpos->right->number = numbers;
                return;
            }

    }

       //cout<<"number inserted\n";
}

 bool BST:: findNode(int key)
{

    node *searcher= root;
    while(searcher!=nullptr )
    {
        if(searcher->number==key)
        {
            return true;
        }
        else if(searcher->number>key)
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
        return false;
    }
}

// 3 conditions
 /* node being deleted is a leaf node
    2. node has only one child empty
    3. node has both children
    */
void BST::deleteNode(int key)
{
    node *searcher= root;
    node * before = searcher;
    // case1

    if( root->number==key)
    {
        while(searcher!=nullptr)
        {
            before = searcher;
            searcher=searcher->right;
        }
        root->number= before->number;
        return;
    };

    while(searcher!=nullptr)
    {
        if(searcher->number==key)
        {
            if(searcher->left==nullptr && searcher->right==nullptr)
            {
                delete searcher;
                searcher= nullptr;
                before = searcher;
                cout<<key<<" deleted\n";
                return;
            }
            else if(searcher->left == nullptr && searcher->right !=nullptr)
            {
                before->right = searcher->right;
                delete searcher;
                searcher = nullptr;
                cout<<key<<" deleted\n";
                return;
            }
            else if(searcher->left!=nullptr && searcher->right==nullptr)
            {
                before->left = searcher->left;
                delete searcher;
                searcher= nullptr;
                cout<<key<<" deleted\n";
                return;
            }
            else if(searcher->left!=nullptr && searcher->right!=nullptr)
            {
                node* mainpos = searcher;
                while(searcher!=nullptr)
                {
                    before = searcher;
                    searcher = searcher->right;
                }
                mainpos->number= before->number;
                delete before;
                before = nullptr;
                cout<<key<<" deleted\n";
                return;
            }
        }
        if(searcher->number>key)
            {
                before=searcher;
                searcher = searcher->left;
               // left = searcher->left;
                //right = searcher->right;
            }
            else if(searcher->number<key)
            {
                before = searcher;
                searcher=searcher->right;
                //left = searcher->left;
               // right = searcher->right;
            };
    }
    if(searcher==nullptr)
        cout<<"Value not in tree\n";
}


void BST::sortedOrder()
{
    node * printer = root;


}

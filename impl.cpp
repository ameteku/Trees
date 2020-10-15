#include "thehead.h"
//precondtion: function is called and user input is a number
//return option selected
int options()
{
    int num;
    cout<<"1.Search a node in BST\n"
        <<"2.Insert a new node into BST.\n"
        <<"3.Delete an existing node in BST.\n"
        <<"4.Prints out the keys for a BST in sorted order\n"
        <<"5.Display all nodes in a tree format.\n"
        <<"6. cost of the most expensive path\n"
        <<"7. end It\n";
        cin>>num;
    while(cin.fail() || num<1 || num>7) //checking for wrong input
    {
        cout<<"wrong input try again\n";
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        cin>>num;
    }
    ;
    return num;
}


// precond: number is passed in function
// post: number is placed in node and inserted
void BST:: insertNode(int numbers)
{

    //if its the first number, set root to it
    if(root==nullptr)
    {
        root = new node;
        root->number = numbers;
        cout<<root->number<<endl;
        return;
    }
    else // if root is already filled
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

        if( initialpos->number>numbers) // find position oto place node
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

}

//precond: key or number is passed to function
// return true of false if found
 bool BST:: findNode(int key)
{

    node *searcher= root; // pointer for searching is init
    while(searcher!=nullptr )
    {
        if(searcher->number==key)
        {
            return true; // returning true if found
        }
        else if(searcher->number>key) // checking thorugh tree to see
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

// precond: number is passed into function

 /* 3 conditions
    node being deleted is a leaf node
    2. node has only one child empty
    3. node has both children
    */
    //condition: number is deleted or 'not found' is returned
void BST::deleteNode(int key)
{
    //initialization
    node *searcher= root;
    node * before = nullptr;


    if(root ==nullptr)
    {
        cout<<"tree empty\n";
        return;
    }

    //if number is found in root
    if(root->number==key)
    {
        //if root is the only node
        if(root->left==nullptr && root->right==nullptr)
        {
            root=nullptr;
            cout<<key<<" deleted\n";
            return;
        }
        //finding the smallest number to the right of root
        if(root->right!=nullptr)
        {
            before = searcher;
            searcher = searcher->right;
        }

        // pushing the pointer left if possible
        while(searcher->left!=nullptr)
        {
            before = searcher;
            searcher= searcher->left;
        }

        // checking if right children are linked to the number being taken out
        if(searcher->right!=nullptr)
        {
            if(searcher->number> before->number)
             before->right = searcher->right;
            if(searcher->number<before->number)
                before->left = searcher->right;
        }
        else
        {
            if(searcher->number> before->number)
             before->right = nullptr;
            if(searcher->number<before->number)
                before->left = nullptr;
        }
        root->number = searcher->number;
        delete searcher;
        searcher = nullptr;

        cout<<key<<" deleted\n";
        return;
    };

    // code for all other nodes
    while(searcher!=nullptr)
    {
        if(searcher->number>key)
        {
            before=searcher;
            searcher = searcher->left;
        }
        else if(searcher->number<key)
        {
            before = searcher;
            searcher=searcher->right;
        };
         //if number is found
        if(searcher->number==key)
        {
            // if its a leaf node
            if(searcher->left==nullptr && searcher->right==nullptr)
            {
                if(searcher->number<before->number)
                    before->left = nullptr;
                else
                    before->right = nullptr;
                delete searcher;
                searcher= nullptr;
                cout<<key<<" deleted\n";
                return;
            }
            //if it has only right children
            else if(searcher->left == nullptr && searcher->right !=nullptr)
            {
                if(searcher->number<before->number)
                    before->left = searcher->right;
                else
                    before->right = searcher->right;
                delete searcher;
                searcher = nullptr;
                cout<<key<<"deleted\n";
                return;
            }
            //if it has only left children
            else if(searcher->left!=nullptr && searcher->right==nullptr)
            {
                if(searcher->number<before->number)
                    before->left = searcher->left;
                else
                    before->right = searcher->left;

                delete searcher;
                searcher= nullptr;
                cout<<key<<"deleted\n";
                return;
            }
            //if it has all children in place
            else if(searcher->left!=nullptr && searcher->right!=nullptr)
            {
                node* mainpos = searcher;
                searcher = searcher->right;

                while(searcher->left!=nullptr)
                {
                    before = searcher;
                    searcher= searcher->left;
                }
                mainpos->number = searcher->number;
                if(searcher->right!=nullptr)
                {
                    if(searcher->number>before->number)
                        before->right = searcher->right;
                    else
                        before->left = searcher->right;
                }
                else
                {
                    if(searcher->number>before->number)
                        before->right = nullptr;
                    else
                        before->left = nullptr;
                }
                delete searcher;
                searcher= nullptr;
                cout<<mainpos->number<<" is new large\n";
                return;
            }
        }

    }

    //if not found
    if(searcher==nullptr)
        cout<<"Value not in tree\n";
}


// precond: node pointer is passed into function
// postcond: nuumbers in the nodes are printed in order
void BST::printNode(node * right)
{
    //base case : if leaf nodes are empty
    if(right==nullptr)
    {
        return;
    }
    else if(right->right !=nullptr)
    {
        printNode(right->right);
    }
    cout<<right->number<<" ";
    if(right->left==nullptr)
            return;
    else if(right->left!=nullptr)
    {
        printNode(right->left);
    }
    return;



}

// precond: function is called and tree is intialized
// postcond: numbers are printed in order from ascending to descending
void BST::sortedOrder()
{
    node * curNode = root;
    if(curNode!=nullptr)
    {
        printNode(curNode->right);
        cout<<curNode->number<<" ";
        if(curNode->left!=nullptr)
        {
            printNode(curNode->left);
        }
        cout<<endl;
        return;
    }
    cout<<"tree is empty\n";
}

// precond: node pointer is passed
// post: finds and return the largest number combination in the tree
double BST::adder(node * ROL)
{
    double  mainNumber = ROL->number;
    double leftNumber=0;
    double rightNumber = 0;
    if(ROL->left==nullptr && ROL->right==nullptr)
        return mainNumber;

    if(ROL->right!=nullptr)
    {
        rightNumber= mainNumber+adder(ROL->right);
    }
    if(ROL->left!=nullptr)
    {
        leftNumber = mainNumber + adder(ROL->left);
    }

    return (rightNumber>=leftNumber ) ? rightNumber : leftNumber;
};


// precond: function is called
//postond: prints out most expensive path.
void BST::findCost()
{
    if(root==nullptr)
    {
        cout<<"no node\n";
        return;
    }

    cout<<"The most expensive path is: "<<adder(root)<<endl;
}


// precond: node pointer is passed
// postcond: height if the tree is returned
int BST::longestnode(node *ROL)
{
    int leftNumber=0;
    int rightNumber = 0;
    if(ROL->left==nullptr && ROL->right==nullptr)
        return 1;

    if(ROL->right!=nullptr)
    {
        rightNumber= 1+longestnode(ROL->right);
    }
    if(ROL->left!=nullptr)
    {
        leftNumber = 1 + longestnode(ROL->left);
    }

    return (rightNumber>=leftNumber ) ? rightNumber : leftNumber;
};

//precond: dynamic array, node pointer and position is passed into array
// post:adding all numbers in tree to tree array
void BST::addToTree( node *child, int* treearr, int pos)
{
    treearr[pos]=child->number;

    if(child->right!=nullptr)
        addToTree(child->right,treearr,2*pos+1);
    if(child->left!=nullptr)
        addToTree(child->left,treearr,2*pos);
    return;
}

//pre: function is called
//post: numbers in tree are printed.
void BST::printTreeFormat()
{
    if(root==nullptr)
    {
        cout<<"root empty\n";
        return;
    }
    //declarations
    int *numtree;
    int leftside=0;
    int rightside=0 ;
    int arrsize ;
    int depth;
    int position = 1;
    int spaces = 60;

    //finding depth of tree
    rightside = longestnode(root->right);
    leftside = longestnode(root->left);
    depth = leftside>=rightside? leftside:rightside;

    arrsize = pow(2.0,depth+1)-1; //max number nodes needed in that height
    numtree = new int[arrsize]; //getting the array need to store all numbers
    for(int i =0; i<arrsize; i++)
        numtree[i]=0;

    addToTree(root,numtree,position); // adding all numbers in tree to tree array

    int pos = 1;
    int maxpos=0;


    for(int level = 0; level<=depth; level++)
    {
        maxpos+= pow(2,level);

        cout<<setw(100-((level+1)*10))<<"\'";
        for(;pos<=maxpos;pos++)
        {
            cout<<numtree[pos]<<setw((depth*10)-level*2);

        }
        cout<<endl;
    }

}

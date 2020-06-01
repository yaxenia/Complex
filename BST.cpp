#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to
   left child and a pointer to right child */
class Node
{
public :
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Returns true if given tree is BST.
bool isBST(Node* root, Node* l=nullptr, Node* r = nullptr)
{
    // Base condition
    if (root == nullptr)
        return true;

    // if left node exist then check it has
    // correct data or not i.e. left node's data
    // should be less than root's data
    if (l != nullptr && root->data < l->data)
        return false;

    // if right node exist then check it has
    // correct data or not i.e. right node's data
    // should be greater than root's data
    if (r != nullptr && root->data > r->data)
        return false;

    // check recursively for every node.
    return isBST(root->left, l, root) and
           isBST(root->right, root, r);
}

int main()
{
    int number, n , a,b;
    string an,k;
    std :: cin >> n;
    std :: cin >> number;
    cin >> a>> an >> b;
    Node *root = new Node(a);
    if( an == "L")
        root->left = new Node(b);
    if (an == "R")
        root-> right = new Node(b);

    if(isBST(root))
            cout<<"Is BST";
        else
            cout<<"Not a BST";


    return 0;
}

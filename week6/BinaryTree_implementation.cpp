#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *create()
{
    int x;
    node *newnode = new node();
    cout << "Enter data (-1 for no node): ";
    cin >> x;
    if (x == -1)
    {
        return nullptr;
    }
    else
    {
        newnode->data = x;
        cout << "Enter the left child of " << x << ": ";
        newnode->left = create();
        cout << "Enter the right child of " << x << ": ";
        newnode->right = create();
        return newnode;
    }
}

void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node *root = create();
    cout << "In-order traversal of the binary tree: ";
    inorder(root);
    return 0;
}
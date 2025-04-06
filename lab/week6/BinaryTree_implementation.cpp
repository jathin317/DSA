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
        cout << "Enter the left child of " << x << ":\n";
        newnode->left = create();
        cout << "Enter the right child of " << x << ":\n";
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

// Updated Sample Output:
// Enter data (-1 for no node): 1
// Enter the left child of 1:
// Enter data (-1 for no node): 2
// Enter the left child of 2:
// Enter data (-1 for no node): -1
// Enter the right child of 2:
// Enter data (-1 for no node): -1
// Enter the right child of 1:
// Enter data (-1 for no node): 3
// Enter the left child of 3:
// Enter data (-1 for no node): -1
// Enter the right child of 3:
// Enter data (-1 for no node): -1
// In-order traversal of the binary tree: 2 1 3
/*Find width of a binary tree*/
#include <iostream>
#include <cmath>
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
        cout << "Enter the left child of " << x << ": " << endl;
        newnode->left = create();
        cout << "Enter the right child of " << x << ": " << endl;
        newnode->right = create();
        return newnode;
    }
}
int getDepth(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
}
int main()
{
    node *root = create();
    cout << "Depth of tree = " << getDepth(root) - 1;
    cout << "Width of tree = " << pow(2, getDepth(root) - 1);
    return 0;
}

/*
Sample Output:
Enter data (-1 for no node): 1
Enter the left child of 1:
Enter data (-1 for no node): 2
Enter the left child of 2:
Enter data (-1 for no node): -1
Enter the right child of 2:
Enter data (-1 for no node): -1
Enter the right child of 1:
Enter data (-1 for no node): 3
Enter the left child of 3:
Enter data (-1 for no node): -1
Enter the right child of 3:
Enter data (-1 for no node): -1
Depth of tree = 1
Width of tree = 2
*/

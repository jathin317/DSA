/*Find diameter of a binary tree(longest path)*/
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
        cout << "Enter the left child of " << x << ": " << endl;
        newnode->left = create();
        cout << "Enter the right child of " << x << ": " << endl;
        newnode->right = create();
        return newnode;
    }
}

int height(node *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameter(node *root)
{
    if (root == nullptr)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

int main()
{
    node *root = create();
    cout << "Diameter of the tree: " << diameter(root) << endl;
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
Diameter of the tree: 3
*/

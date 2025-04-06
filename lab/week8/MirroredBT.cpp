/*Find whether the tree is a mirrored binary tree*/
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
void Mirror(node *root1, node *&root2)
{
    if (root1 == nullptr)
        return;
    else
    {
        node *temp = new node();
        temp->data = root1->data;
        root2 = temp;
        Mirror(root1->left, root2->right);
        Mirror(root1->right, root2->left);
    }
}
void displayInorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    displayInorder(root->left);
    cout << root->data << " ";
    displayInorder(root->right);
}
int main()
{
    node *root1 = create();
    node *root2 = nullptr;
    Mirror(root1, root2);
    cout << "Inorder traversal of the original tree: ";
    displayInorder(root1);
    cout << "Inorder traversal of the mirrored tree: ";
    displayInorder(root2);
    return 0;
}

/*
Sample Output:
Enter data (-1 for no node): 4
Enter the left child of 4:
Enter data (-1 for no node): 2
Enter the left child of 2:
Enter data (-1 for no node): -1
Enter the right child of 2:
Enter data (-1 for no node): -1
Enter the right child of 4:
Enter data (-1 for no node): 6
Enter the left child of 6:
Enter data (-1 for no node): -1
Enter the right child of 6:
Enter data (-1 for no node): -1
Inorder traversal of the original tree: 2 4 6
Inorder traversal of the mirrored tree: 6 4 2
*/

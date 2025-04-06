/*Find the maximum value in a binary tree. Also determine the depth of the tree*/
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
    int depth = 0;
};
int maximum = -100;
node *create()
{
    int x;
    cout << "Enter data (-1 for no node): ";
    cin >> x;
    if (x == -1)
        return 0;
    else
    {
        node *newnode = new node;
        newnode->data = x;
        cout << "Enter left child of " << x << endl;
        newnode->left = create();
        cout << "Enter right child of " << x << endl;
        newnode->right = create();
        return newnode;
    }
}
void Inorder(node *root)
{

    if (root == nullptr)
        return;
    root->depth += 1;
    if (maximum < root->data)
    {
        maximum = root->data;
    }
    Inorder(root->left);
    Inorder(root->right);
}
int findDepth(node *root)
{
    if (root == nullptr)
        return 0;
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}
int main()
{
    node *root = create();
    Inorder(root);
    int depth = findDepth(root);
    cout << "Maximum number=" << maximum << endl;
    cout << "Depth= " << depth << endl;
}

/*
Output:
Enter data (-1 for no node): 10
Enter left child of 10
Enter data (-1 for no node): 20
Enter left child of 20
Enter data (-1 for no node): -1
Enter right child of 20
Enter data (-1 for no node): -1
Enter right child of 10
Enter data (-1 for no node): 30
Enter left child of 30
Enter data (-1 for no node): -1
Enter right child of 30
Enter data (-1 for no node): -1
Maximum number=30
Depth= 2
*/

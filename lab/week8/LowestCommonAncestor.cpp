/*Find lowewst common ancestor between two nodes*/
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

node *findLCA(node *root, int n1, int n2)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == n1 || root->data == n2)
        return root;

    node *leftLCA = findLCA(root->left, n1, n2);
    node *rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main()
{
    node *root = create();
    int n1, n2;
    cout << "Enter the first node: ";
    cin >> n1;
    cout << "Enter the second node: ";
    cin >> n2;
    node *lca = findLCA(root, n1, n2);
    if (lca != nullptr)
        cout << "Lowest Common Ancestor: " << lca->data << endl;
    else
        cout << "Lowest Common Ancestor not found." << endl;
    return 0;
}

/*
Sample Output:
Enter data (-1 for no node): 3
Enter the left child of 3:
Enter data (-1 for no node): 5
Enter the left child of 5:
Enter data (-1 for no node): -1
Enter the right child of 5:
Enter data (-1 for no node): -1
Enter the right child of 3:
Enter data (-1 for no node): 1
Enter the left child of 1:
Enter data (-1 for no node): -1
Enter the right child of 1:
Enter data (-1 for no node): -1
Enter the first node: 5
Enter the second node: 1
Lowest Common Ancestor: 3
*/

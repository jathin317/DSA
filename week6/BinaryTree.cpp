#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

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
        cout << "Enter left child of " << x;
        newnode->left = create();
        cout << "Enter right child of " << x;
        newnode->right = create();
        return newnode;
    }
}
void displayInorder(node *root)
{
    if (root == 0)
        return;
    displayInorder(root->left);
    cout << root->data << " ";
    displayInorder(root->right);
}
void displayPreorder(node *root)
{
    if (root == 0)
        return;
    cout << root->data << " ";
    displayPreorder(root->left);
    displayPreorder(root->right);
}
void displayPostorder(node *root)
{
    if (root == 0)
        return;
    displayPostorder(root->left);
    displayPostorder(root->right);
    cout << root->data << " ";
}
int main()
{
    node *root = create();
    int ch;
    do
    {
        cout << "1. Inorder\n2. Preorder\n3. Postorder\n4. Exit" << endl;
        ;
        cout << "Enter your choice";
        cin >> ch;
        switch (ch)
        {
        case 1:
            displayInorder(root);
            cout << endl;
            break;
        case 2:
            displayPreorder(root);
            cout << endl;
            break;
        case 3:
            displayPostorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Exiting";
            break;
        default:
            cout << "Invalid Input! Try again" << endl;
        }
    } while (ch != 4);
    return 0;
}
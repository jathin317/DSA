/*BST traversal in recursive and non-recursive way*/
#include <iostream>
#include <stack>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};

void inorderRecursive(node *root)
{
    if (root == nullptr)
        return;
    inorderRecursive(root->left);
    cout << root->data << " ";
    inorderRecursive(root->right);
}

void inorderNonRecursive(node *root)
{
    stack<node *> s;
    node *current = root;
    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

int main()
{
    node *root = new node{10, nullptr, nullptr};
    root->left = new node{5, nullptr, nullptr};
    root->right = new node{15, nullptr, nullptr};
    root->left->left = new node{3, nullptr, nullptr};
    root->left->right = new node{7, nullptr, nullptr};

    cout << "Recursive Inorder Traversal: ";
    inorderRecursive(root);
    cout << endl;

    cout << "Non-Recursive Inorder Traversal: ";
    inorderNonRecursive(root);
    cout << endl;

    return 0;
}

/*
Output:
Recursive Inorder Traversal: 3 5 7 10 15
Non-Recursive Inorder Traversal: 3 5 7 10 15
*/

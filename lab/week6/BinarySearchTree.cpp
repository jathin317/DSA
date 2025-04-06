#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};

node *insert(node *root, int x)
{
    if (root == nullptr)
    {
        node *newnode = new node;
        newnode->data = x;
        newnode->left = newnode->right = nullptr;
        return newnode;
    }
    if (x < root->data)
    {
        root->left = insert(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = insert(root->right, x);
    }
    return root;
}

node *findMin(node *root)
{
    while (root->left != nullptr)
        root = root->left;
    return root;
}

node *Delete(node *root, int x)
{
    // Base case: if the tree is empty
    if (root == nullptr)
        return root;

    // If the value to be deleted is smaller than the root's value,
    // then it lies in the left subtree
    if (x < root->data)
        root->left = Delete(root->left, x);

    // If the value to be deleted is greater than the root's value,
    // then it lies in the right subtree
    else if (x > root->data)
        root->right = Delete(root->right, x);

    // If the value is the same as the root's value, then this is the node to be deleted
    else
    {
        // Node with no child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // Node with only one child
        else if (root->left == nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        node *temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = Delete(root->right, temp->data);
    }
    return root;
}

void displayInorder(node *root)
{
    if (root == 0)
        return;
    displayInorder(root->left);
    cout << root->data << " ";
    displayInorder(root->right);
}

int main()
{
    node *root = nullptr;
    int n, x;
    cout << "Enter number of nodes:\n";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter data for node " << i + 1 << ":\n";
        cin >> arr[i];
        root = insert(root, arr[i]);
    }
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display Inorder\n";
        cout << "4. Exit\n";
        cout << "Enter your choice:\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data to insert:\n";
            cin >> x;
            root = insert(root, x);
            break;
        case 2:
            cout << "Enter data to delete:\n";
            cin >> x;
            root = Delete(root, x);
            break;
        case 3:
            cout << "Inorder Traversal: ";
            displayInorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
    displayInorder(root);
    return 0;
}

// Updated Sample Output:
// Enter number of nodes:
// 5
// Enter data for node 1:
// 50
// Enter data for node 2:
// 30
// Enter data for node 3:
// 70
// Enter data for node 4:
// 20
// Enter data for node 5:
// 40
//
// Menu:
// 1. Insert
// 2. Delete
// 3. Display Inorder
// 4. Exit
// Enter your choice:
// 3
// Inorder Traversal: 20 30 40 50 70
//
// Enter your choice:
// 2
// Enter data to delete:
// 30
//
// Enter your choice:
// 3
// Inorder Traversal: 20 40 50 70
//
// Enter your choice:
// 4
// Exiting...
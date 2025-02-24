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
void Delete(node *root,int x)
{
    while(root->data != x)
    {
        if(x < root->data)
        {
            root = root->left;
        }
        else if(x > root->data)
        {
            root = root->right;
        }
    }   
    if(root->left == nullptr && root->right == nullptr)
    {
        delete root;
    }
    else if(root->left == nullptr)
    {
        node *temp = root;
        root = root->right;
        delete temp;
    }
    else if(root->right == nullptr)
    {
        node *temp = root;
        root = root->left;
        delete temp;
    }
    else
    {
        node *temp = root->right;
        while(temp->left != nullptr)
        {
            temp = temp->left;
        }
        root->data = temp->data;
        delete temp;
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

int main()
{
    node *root = nullptr;
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> arr[i];
        root = insert(root, x);
    }
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display Inorder\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> x;
                root = insert(root, x);
                break;
            case 2:
                cout << "Enter data to delete: ";
                cin >> x;
                Delete(root, x);
                break;
            case 3:
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
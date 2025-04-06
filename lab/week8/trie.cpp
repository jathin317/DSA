#include <iostream>
using namespace std;

struct node
{
    char data;
    node *next[26];
    bool isEnd;
};

node *createNode(char c)
{
    node *newNode = new node();
    newNode->data = c;
    for (int i = 0; i < 26; i++)
    {
        newNode->next[i] = NULL;
    }
    newNode->isEnd = false;
    return newNode;
}

void insert(node *root, string s)
{
    node *temp = root;
    for (int i = 0; i < (int)s.length(); i++)
    {
        int index = s[i] - 'a';
        if (temp->next[index] == NULL)
        {
            temp->next[index] = createNode(s[i]);
        }
        temp = temp->next[index];
    }
    temp->isEnd = true;
}

// Function to search for a string in the Trie
bool search(node *root, string s)
{
    node *temp = root;
    for (int i = 0; i < (int)s.length(); i++)
    {
        int index = s[i] - 'a';
        if (temp->next[index] == NULL)
        {
            return false;
        }
        temp = temp->next[index];
    }
    return temp->isEnd;
}

// Function to print all strings stored in the Trie
void print(node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->isEnd == true)
    {
        cout << endl;
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->next[i] != NULL)
        {
            cout << root->next[i]->data;
            print(root->next[i]);
        }
    }
}
int main()
{
    node *root = createNode('/');
    do
    {
        cout << "1. Insert\n2. Search\n3. Print\n4. Exit\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string s;
            cout << "Enter the string to insert: ";
            cin >> s;
            insert(root, s);
            break;
        }
        case 2:
        {
            string s;
            cout << "Enter the string to search: ";
            cin >> s;
            if (search(root, s))
            {
                cout << "String found\n";
            }
            else
            {
                cout << "String not found\n";
            }
            break;
        }
        case 3:
        {
            print(root);
            break;
        }
        case 4:
        {
            exit(0);
        }
        default:
        {
            cout << "Invalid choice\n";
        }
        }
    } while (1);
}

/*
Sample Output:
1. Insert
2. Search
3. Print
4. Exit
1
Enter the string to insert: apple
1. Insert
2. Search
3. Print
4. Exit
1
Enter the string to insert: app
1. Insert
2. Search
3. Print
4. Exit
2
Enter the string to search: app
String found
1. Insert
2. Search
3. Print
4. Exit
3
a
p
p
l
e
1. Insert
2. Search
3. Print
4. Exit
4
*/
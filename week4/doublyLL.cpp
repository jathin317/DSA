/*implement doubly linked list with insertion and deletion operation.Considering all cases*/
#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next = nullptr;
    struct node *prev = nullptr;
} node;
void insertAtBegginning(int value, node **head)
{
    node *newnode = new node();
    newnode->data = value;
    newnode->next = *head;
    newnode->prev = nullptr;
    (*head)->prev = newnode;
    *head = newnode;
}
void insertAtEnd(int value, node **head)
{
    node *newnode = new node();
    newnode->data = value;
    newnode->next = nullptr;
    node *temp = *head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}
void insertAtPosition(int value, node **head, int position)
{
    if (position < 1)
    {
        cout << "Position should be >= 1." << endl;
        return;
    }

    node *newnode = new node();
    newnode->data = value;
    newnode->prev = nullptr;
    newnode->next = nullptr;

    if (position == 1)
    {
        insertAtBegginning(value, head);
    }

    node *temp = *head;
    int counter = 1;
    while (temp != nullptr && counter < position - 1)
    {
        temp = temp->next;
        counter++;
    }

    if (temp == nullptr)
    {
        cout << "Position out of range" << endl;
        delete newnode;
        return;
    }

    newnode->next = temp->next;
    if (temp->next != nullptr)
    {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    newnode->prev = temp;
}
void deleteNode(int position, node **head)
{
    if (*head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *temp = *head;

    if (position == 1)
    {
        *head = temp->next;
        if (*head != nullptr)
        {
            (*head)->prev = nullptr;
        }
        delete temp;
        return;
    }

    int counter = 1;
    while (temp != nullptr && counter < position)
    {
        temp = temp->next;
        counter++;
    }

    if (temp == nullptr)
    {
        cout << "Position out of range" << endl;
        return;
    }

    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
}
void display(node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    node *head = new node();
    cout << "Enter the data: ";
    cin >> head->data;
    node *temp = head;
    for (int i = 2; i <= n; i++)
    {
        node *newnode = new node();
        cout << "Enter the data: ";
        cin >> newnode->data;
        newnode->next = nullptr;
        newnode->prev = temp;
        temp->next = newnode;
        temp = temp->next;
    }
    while (1)
    {
        int val;
        char ch;
        cout << "1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete node\n5.Display\n6.Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            cout << "Enter the value to be inserted: ";
            cin >> val;
            insertAtBegginning(val, &head);
            break;
        case '2':
            cout << "Enter the value to be inserted: ";
            cin >> val;
            insertAtEnd(val, &head);
            break;
        case '3':
            int pos;
            cout << "Enter the value to be inserted: ";
            cin >> val;
            cout << "Enter the position: ";
            cin >> pos;
            insertAtPosition(val, &head, pos);
            break;
        case '4':
            int position;
            cout << "Enter the position to be deleted: ";
            cin >> position;
            deleteNode(position, &head);
            break;
        case '5':
            display(head);
            break;
        case '6':
            exit(0);
        default:
            cout << "Invalid choice!Try again" << endl;
        }
    }
}
/*implement singly linked list with insertion and deletion operation.Considering all cases*/
#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next = nullptr;
} node;
void insertAtBegginning(int value, node **head)
{
    node *newnode = new node();
    newnode->data = value;
    newnode->next = *head;
    *head = newnode;
}
void insertAtEnd(int value, node **head)
{
    node *newnode = new node();
    newnode->data = value;
    newnode->next = nullptr;
    if (*head == nullptr)
    {
        *head = newnode;
        return;
    }
    node *temp = *head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void insertionAtPosition(int value, node **head, int position)
{
    node *newnode = new node();
    newnode->data = value;
    if (position == 1)
    {
        insertAtBegginning(value, head);
    }
    node *temp = *head;
    for (int i = 1; i < position - 1; i++)
    {
        if (temp == nullptr)
        {
            cout << "Position not found" << endl;
            return;
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void deleteAtBegginning(node **head)
{
    if (*head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    delete temp;
}
void deletionAtEnd(node **head)
{
    if (*head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    if ((*head)->next == nullptr)
    {
        delete *head;
        *head = nullptr;
        return;
    }
    node *temp = *head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
void deletionAtPosition(node **head, int position)
{
    if (*head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (position == 1)
    {
        deleteAtBegginning(head);
        return;
    }
    node *temp = *head;
    for (int i = 1; i < position - 1; i++)
    {
        if (temp == nullptr)
        {
            cout << "Position not found" << endl;
            return;
        }
        temp = temp->next;
    }
    if (temp->next == nullptr)
    {
        cout << "Position not found" << endl;
        return;
    }
    node *temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
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
    node *head = nullptr; // Initialize head as nullptr
    if (n > 0)
    {
        cout << "Enter the data: ";
        int data;
        cin >> data;
        head = new node();
        head->data = data;
        node *temp = head;
        for (int i = 2; i <= n; i++)
        {
            node *newnode = new node();
            cout << "Enter the data: ";
            cin >> newnode->data;
            newnode->next = nullptr;
            temp->next = newnode;
            temp = newnode;
        }
    }
    char ch;

    while (1)
    {
        cout << "MENU\n1. Insertion at beginning\n2. Insertion at end\n3. Insertion at position\n4. Deletion at beginning\n5. Deletion at end\n6. Deletion at position\n7. Display\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        int value;
        switch (ch)
        {
        case '1':
            cout << "Enter the value to be inserted: ";
            cin >> value;
            insertAtBegginning(value, &head);
            break;
        case '2':
            cout << "Enter the value to be inserted: ";
            cin >> value;
            insertAtEnd(value, &head);
            break;
        case '3':
            int position;
            cout << "Enter the value to be inserted: ";
            cin >> value;
            cout << "Enter the position: ";
            cin >> position;
            insertionAtPosition(value, &head, position);
            break;
        case '4':
            deleteAtBegginning(&head);
            break;
        case '5':
            deletionAtEnd(&head);
            break;
        case '6':
            int pos;
            cout << "Enter the position: ";
            cin >> pos;
            deletionAtPosition(&head, pos);
            break;
        case '7':
            display(head);
            break;
        case '8':
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

/*
Sample Output:
Enter the number of nodes: 3
Enter the data: 10
Enter the data: 20
Enter the data: 30
MENU
1. Insertion at beginning
2. Insertion at end
3. Insertion at position
4. Deletion at beginning
5. Deletion at end
6. Deletion at position
7. Display
8. Exit
Enter your choice: 7
10 20 30
Enter your choice: 1
Enter the value to be inserted: 5
Enter your choice: 7
5 10 20 30
Enter your choice: 3
Enter the value to be inserted: 15
Enter the position: 3
Enter your choice: 7
5 10 15 20 30
Enter your choice: 6
Enter the position: 2
Enter your choice: 7
5 15 20 30
Enter your choice: 8
*/
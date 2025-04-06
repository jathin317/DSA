#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next = nullptr;
};
void insertAtBegginning(int value, node **head, node **tail)
{
    node *newnode = new node();
    newnode->data = value;
    if (*head == nullptr)
    {
        *head = newnode;
        *tail = newnode;
        newnode->next = *head;
    }
    else
    {
        newnode->next = *head;
        *head = newnode;
        (*tail)->next = *head;
    }
}
void insertAtPosition(int value, int position, node **head, node **tail)
{
    node *newnode = new node();
    newnode->data = value;
    if (position == 1)
    {
        insertAtBegginning(value, head, tail);
    }
    else
    {
        node *temp = *head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        if (newnode->next == *head)
        {
            *tail = newnode;
        }
    }
}
void deleteAtPosition(int position, node **head, node **tail)
{
    if (position == 1)
    {
        node *temp = *head;
        *head = (*head)->next;
        (*tail)->next = *head;
        delete temp;
    }
    else
    {
        node *temp = *head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        node *temp1 = temp->next;
        temp->next = temp1->next;
        if (temp1 == *tail)
        {
            *tail = temp;
        }
        delete temp1;
    }
}
void display(node *head, node *tail)
{
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main()
{
    node *head = nullptr;
    node *tail = nullptr;
    cout << "1. Insert at begginning\n2. Insert at position\n3. Delete at position\n4. Display\n5. Exit\n";
    int choice;
    do
    {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter value: ";
            cin >> value;
            insertAtBegginning(value, &head, &tail);
            break;
        case 2:
            int value1, position;
            cout << "Enter value and position: ";
            cin >> value1 >> position;
            insertAtPosition(value1, position, &head, &tail);
            break;
        case 3:
            int position1;
            cout << "Enter position: ";
            cin >> position1;
            deleteAtPosition(position1, &head, &tail);
            break;
        case 4:
            display(head, tail);
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);
}

/*
Sample Output:
1. Insert at beginning
2. Insert at position
3. Delete at position
4. Display
5. Exit
Enter choice: 1
Enter value: 10
Enter choice: 1
Enter value: 20
Enter choice: 4
20 10
Enter choice: 2
Enter value and position: 15 2
Enter choice: 4
20 15 10
Enter choice: 3
Enter position: 2
Enter choice: 4
20 10
Enter choice: 5
*/
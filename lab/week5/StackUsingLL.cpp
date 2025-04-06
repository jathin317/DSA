#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **head, int data)
{
    Node *newnode = new Node();
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}

int pop(Node **head)
{
    if (*head == nullptr)
    {
        cout << "Stack underflow" << endl;
        return -1;
    }
    Node *temp = *head;
    *head = (*head)->next;
    int popped = temp->data;
    delete temp;
    return popped;
}

int peek(Node *head)
{
    if (head == nullptr)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return head->data;
}

bool isEmpty(Node *head)
{
    return head == nullptr;
}

void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    int choice, value;

    do
    {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(&head, value);
            break;

        case 2:
            cout << "Popped value: " << pop(&head) << endl;
            break;

        case 3:
            cout << "Top value: " << peek(head) << endl;
            break;

        case 4:
            display(head);
            break;

        case 5:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    } while (1);

    return 0;
}

/*
Sample Output:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter value to push: 10
Enter your choice: 1
Enter value to push: 20
Enter your choice: 4
20 10
Enter your choice: 3
Top value: 20
Enter your choice: 2
Popped value: 20
Enter your choice: 4
10
Enter your choice: 5
Exiting...
*/
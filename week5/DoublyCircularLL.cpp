#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
void insertAtBeginning(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = (*head)->prev;
    (*head)->prev->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;
}
void insertAtPosition(Node **head, int data, int position)
{
    Node *newNode = new Node();
    newNode->data = data;
    Node *temp = *head;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
void deleteAtPosition(Node **head, int position)
{
    Node *temp = *head;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    Node *temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next->prev = temp;
    delete temp1;
}
void display(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
int main()
{
    Node *head = new Node();
    int choice;
    cout << "1. Insert at beginning\n2. Insert at position\n3. Delete at position\n4. Display\n5. Exit\n";
    do
    {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter data: ";
            cin >> data;
            if (head->next == NULL)
            {
                head->data = data;
                head->next = head;
                head->prev = head;
            }
            else
            {
                insertAtBeginning(&head, data);
            }
            break;
        case 2:
            int data1, position;
            cout << "Enter data: ";
            cin >> data1;
            cout << "Enter position: ";
            cin >> position;
            insertAtPosition(&head, data1, position);
            break;
        case 3:
            int position1;
            cout << "Enter position: ";
            cin >> position1;
            deleteAtPosition(&head, position1);
            break;
        case 4:
            display(head);
            cout << endl;
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice\n";
        }
    }while(choice != 5);
}
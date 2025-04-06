#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void enqueue(Node **front, Node **rear, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (*front == NULL)
    {
        *front = newNode;
        *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}
void dequeue(Node **front, Node **rear)
{
    if (*front == NULL)
    {
        cout << "Queue id empty\n";
    }
    else
    {
        Node *temp = *front;
        *front = (*front)->next;
        delete temp;
    }
}
void display(Node *front)
{
    if (front == NULL)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
int main()
{
    Node *front = NULL;
    Node *rear = NULL;
    cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
    int choice;
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
            enqueue(&front, &rear, data);
            break;
        case 2:
            dequeue(&front, &rear);
            break;
        case 3:
            display(front);
            break;
        }
    } while (choice != 4);
}

/*
Sample Output:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter data: 10
Enter choice: 1
Enter data: 20
Enter choice: 3
10 20
Enter choice: 2
Enter choice: 3
20
Enter choice: 4
*/
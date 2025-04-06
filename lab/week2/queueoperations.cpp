#include <iostream>
using namespace std;
#define N 5
int front = -1;
int rear = -1;
int queue[N];
void enqueue()
{
    if (front == -1)
    {
        front = 0;
    }
    if (front != N - 1)
    {
        int x;
        cout << "Enter the number: ";
        cin >> x;
        rear += 1;
        queue[rear] = x;
    }
    else
        cout << "Overflow\n";
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Underflow\n";
    }
    else
    {
        front += 1;
    }
}
int main()
{

    char ch = 0;
    while (ch != '6')
    {
        cout << "1 .enqueue\n2. dequeue\n3. size\n4. isfull\n5. isempty\n6. Exit";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            enqueue();
            break;
        case '2':
            dequeue();
            break;
        case '3':
            cout << "Size of queue " << N;
            break;
        case '4':
            if (rear == N - 1)
            {
                cout << "Yes";
            }
            else
                cout << "false";
            break;
        case '5':
            if (front == rear)
            {
                cout << "true";
            }
            else
                cout << "false";
            break;
        case '6':
            break;
        default:
            cout << "Invalid input!Try again.";
        }
    }
}

/*
Sample Output:

1 .enqueue
2. dequeue
3. size
4. isfull
5. isempty
6. Exit
Enter your choice: 1
Enter the number: 10

1 .enqueue
2. dequeue
3. size
4. isfull
5. isempty
6. Exit
Enter your choice: 1
Enter the number: 20

1 .enqueue
2. dequeue
3. size
4. isfull
5. isempty
6. Exit
Enter your choice: 4
false

1 .enqueue
2. dequeue
3. size
4. isfull
5. isempty
6. Exit
Enter your choice: 5
false

1 .enqueue
2. dequeue
3. size
4. isfull
5. isempty
6. Exit
Enter your choice: 2

1 .enqueue
2. dequeue
3. size
4. isfull
5. isempty
6. Exit
Enter your choice: 5
true

1 .enqueue
2. dequeue
3. size
4. isfull
5. isempty
6. Exit
Enter your choice: 6
*/
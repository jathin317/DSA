#include <iostream>
using namespace std;
#define N 5
void push(int *top, int stack[])
{
    int x;
    cout << "Enter data ";
    cin >> x;
    if (*top == N - 1)
    {
        cout << "Overflow\n";
    }
    else
    {
        *top += 1;
        stack[*top] = x;
    }
}

void pop(int *top, int stack[])
{
    int x;
    if (*top == -1)
        cout << "Underflow\n";
    else
    {
        x = stack[*top];
        *top -= 1;
        cout << x << "\n";
    }
}

void peek(int *top, int stack[])
{
    if (*top == -1)
        cout << " Underflow\n";
    else
        cout << stack[*top] << "\n";
}

void display(int *top, int stack[])
{
    int i;
    for (i = *top; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }
}

int main()
{
    int stack[N], top = -1;
    char ch;
    do
    {

        cout << "1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
        cout << "Enter choice:\n";
        cin >> ch;
        switch (ch)
        {
        case '1':
            push(&top, stack);
            break;
        case '2':
            pop(&top, stack);
            break;
        case '3':
            peek(&top, stack);
            break;
        case '4':
            display(&top, stack);
            break;
        case '5':
            cout << "Final Stack\n";
            display(&top, stack);
            return 0;
        default:
            cout << "Invalid input!\n";
            break;
        }
    } while (1);
}

/*
Sample Output:

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter choice:
1
Enter data: 10

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter choice:
1
Enter data: 20

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter choice:
1
Enter data: 30

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter choice:
4
30
20
10

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter choice:
2
30

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter choice:
3
20

1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter choice:
5
Final Stack:
20
10
*/
#include <iostream>
using namespace std;
void pushA(int *arr, int &topA, int &topB, int value)
{
    if (topA == topB - 1)
    {
        cout << "Stack is full\n";
    }
    else
    {
        arr[++topA] = value;
    }
}
void pushB(int *arr, int &topA, int &topB, int value)
{
    if (topB == topA + 1)
    {
        cout << "Stack is full\n";
    }
    else
    {
        arr[--topB] = value;
    }
}
int popA(int *arr, int &topA, int &topB)
{
    if (topA == -1)
    {
        cout << "Stack is empty\n";
        return -1;
    }
    else
    {
        return arr[topA--];
    }
}
int popB(int *arr, int &topA, int &topB, int n)
{
    if (topB == n)
    {
        cout << "Stack is empty\n";
        return -1;
    }
    else
    {
        return arr[topB++];
    }
}
void displayA(int *arr, int topA)
{
    if (topA == -1)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        for (int i = 0; i <= topA; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
void displayB(int *arr, int topB, int n)
{
    if (topB == n)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        for (int i = n - 1; i >= topB; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    int arr[n];
    int topA = -1, topB = n;
    int choice;
    do
    {
        cout << "1. Push in stack A\n2. Push in stack B\n3. Pop from stack A\n4. Pop from stack B\n5. Display stack A\n6. Display stack B\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter value: ";
            cin >> value;
            pushA(arr, topA, topB, value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            pushB(arr, topA, topB, value);
            break;
        case 3:
            cout << popA(arr, topA, topB) << endl;
            break;
        case 4:
            cout << popB(arr, topA, topB, n) << endl;
            break;
        case 5:
            displayA(arr, topA);
            break;
        case 6:
            displayB(arr, topB, n);
            break;
        case 7:
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 7);
}
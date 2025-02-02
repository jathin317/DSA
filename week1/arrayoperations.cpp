#include <iostream>
using namespace std;

void Insertion(int arr[], int *size, int max_size)
{
    if (*size >= max_size)
    {
        cout << "Array is full. Cannot insert more elements." << endl;
        return;
    }
    int element, position;
    cout << "Enter the element and position to insert : ";
    cin >> element >> position;
    if (position < 1 || position > *size + 1)
    {
        cout << "Invalid position. Cannot insert element." << endl;
        return;
    }
    for (int i = *size; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    (*size)++;
}

void Deletion(int arr[], int *size)
{
    if (*size == 0)
    {
        cout << "Array is empty. Cannot delete elements." << endl;
        return;
    }
    int position;
    cout << "Enter the position to delete (1-based index): ";
    cin >> position;
    if (position < 1 || position > *size)
    {
        cout << "Invalid position. Cannot delete element." << endl;
        return;
    }
    for (int i = position - 1; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void Display(int arr[], int size)
{
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int MAX_SIZE = 50;
    int arr[MAX_SIZE], size;

    cout << "Enter the size of the array (max 50): ";
    cin >> size;
    if (size < 0 || size > MAX_SIZE)
    {
        cout << "Invalid size. Exiting program." << endl;
        return 0;
    }

    cout << "Enter elements of the array: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    char ch;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insertion\n";
        cout << "2. Deletion\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case '1':
                Insertion(arr, &size, MAX_SIZE);
                break;
            case '2':
                Deletion(arr, &size);
                break;
            case '3':
                Display(arr, size);
                break;
            case '4':
                cout << "Final array: ";
                Display(arr, size);
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again!" << endl;
                break;
        }
    } while (ch != '4');

    return 0;
}

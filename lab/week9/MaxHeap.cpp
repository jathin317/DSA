#include <iostream>
using namespace std;

void maxHeapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }

    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

void buildMaxHeap(int a[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(a, n, i);
    }
}

void printHeap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    buildMaxHeap(a, n);
    cout << "Max Heap: ";
    printHeap(a, n);
    return 0;
}

/*
Sample Output:
Enter the number of elements: 5
Enter the elements: 3 1 6 5 2
Max Heap: 6 5 3 1 2
*/
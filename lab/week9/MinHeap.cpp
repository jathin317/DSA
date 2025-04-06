#include <iostream>
using namespace std;
void minHeapify(int a[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] < a[smallest])
    {
        smallest = left;
    }
    if (right < n && a[right] < a[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        minHeapify(a, n, smallest);
    }
}
void buildMinHeap(int a[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(a, n, i);
    }
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
    buildMinHeap(a, n);
    cout << "Min Heap: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

/*
Sample Output:
Enter the number of elements: 5
Enter the elements: 3 1 6 5 2
Min Heap: 1 2 6 5 3
*/
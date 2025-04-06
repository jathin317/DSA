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
int maximum(int a[], int n)
{
    return a[0];
}
int extractMax(int a[], int n)
{
    if (n < 1)
    {
        cout << "Heap Underflow" << endl;
        return -1;
    }
    int max = a[0];
    a[0] = a[n - 1];
    n = n - 1;
    maxHeapify(a, n, 0);
    return max;
}
void increaseKey(int a[], int i, int key)
{
    if (key < a[i])
    {
        cout << "New key is smaller than current key" << endl;
        return;
    }
    a[i] = key;
    while (i > 0 && a[(i - 1) / 2] < a[i])
    {
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void buildMaxHeap(int a[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(a, n, i);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    buildMaxHeap(a, n);
    int ch;
    cout << "1. Maximum\n2. Extract Maximum\n3. Increase Key\n4. Print\n5.Exit\n";
    do
    {
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Maximum: " << maximum(a, n) << endl;
            break;
        case 2:
            cout << "Extracted Maximum: " << extractMax(a, n) << endl;
            break;
        case 3:
            int i, key;
            cout << "Enter index and key: ";
            cin >> i >> key;
            increaseKey(a, i, key);
            break;
        case 4:
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
        case 5:
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (ch != 5);
}

/*
Sample Output:
Enter the number of elements: 5
6 5 3 1 2
1. Maximum
2. Extract Maximum
3. Increase Key
4. Print
5.Exit
Enter choice: 1
Maximum: 6
Enter choice: 2
Extracted Maximum: 6
Enter choice: 4
5 2 3 1
Enter choice: 3
Enter index and key: 2 7
Enter choice: 4
7 5 3 1
Enter choice: 5
*/

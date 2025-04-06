/*Write a program to print next largest element of each element of circular array
I/P: 6,3,9,8,10,2,1,15,7
O/P: 9,9,10,15,15,15,-1,9
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of the array :";
    cin >> n;
    int arr[n];
    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i % n];
    }

    int resultant[n];
    for (int j = 0; j < n; j++)
    {
        resultant[j] = -1; // Initialize with -1
        for (int k = 1; k < n; k++)
        {
            int index = (j + k) % n; // Circular traversal
            if (arr[index] > arr[j])
            {
                resultant[j] = arr[index];
                break;
            }
        }
    }
    cout << "Resultant array: ";
    for (int i = 0; i < n; i++)
    {
        cout << resultant[i] << " ";
    }
    return 0;
}

/*
Output:
Enter size of the array :9
Enter elements of the array:
6 3 9 8 10 2 1 15 7
Resultant array: 9 9 10 15 15 15 -1 9 9
*/
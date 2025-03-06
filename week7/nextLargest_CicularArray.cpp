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
        cin >> arr[i%n];
    }
    
    int resultant[n];
    for (int j = 0; j < n; j++)
    {
        int i=0;
        if (j != n - 1)
            i = j + 1;
        for (int k=i; k < n; k++)
        {
            if (arr[k] > arr[j])
            {
                resultant[j] = arr[k];
                break;
            }
            else
                resultant[j] = -1;
        }
    }
    cout << "Resultant array: ";
    for (int i = 0; i < n; i++)
    {
        cout << resultant[i] << " ";
    }
    return 0;
}
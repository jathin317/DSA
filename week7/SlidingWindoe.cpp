/*Given an array of integers, find the maximum value in all the sliding window of length k.
I/P: 11,2,75,92,59,90,55;k=3
O/P: 75,92,92,92,90
*/
#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter k: ";
    cin>>k;
    int result[n-k+1];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    for(int i=0;i<n-k+1;i++)
    {
        result[i]=max(max(arr[i],arr[i+1]),arr[i+2]);
    }
    for(int i=0;i<n-k+1;i++)
    {
        cout<<result[i]<<" ";
    }
}
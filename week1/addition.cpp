#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {3, 2, 1};
    int sum[10];
    int topa = sizeof(a) / sizeof(a[0]) - 1;
    int topb = sizeof(b) / sizeof(b[0]) - 1;
    int tops = 0;
    int carry = 0;

    while (topa >= 0 || topb >= 0 || carry)
    {
        int x = (topa >= 0) ? a[topa--] : 0;
        int y = (topb >= 0) ? b[topb--] : 0;
        int tempSum = x + y + carry;
        sum[tops++] = tempSum % 10;
        carry = tempSum / 10;
    }

    cout << "Sum of two numbers is: ";
    for (int i = tops - 1; i >= 0; i--)
    {
        cout << sum[i];
    }
    cout << endl;

    return 0;
}
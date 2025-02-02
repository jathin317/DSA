#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a_str, b_str;
    cout << "Enter first number: ";
    cin >> a_str;
    cout << "Enter second number: ";
    cin >> b_str;

    int a[100], b[100]; // Assuming the input numbers will not exceed 100 digits
    int a_size = a_str.size();
    int b_size = b_str.size();

    for (int i = 0; i < a_size; ++i)
        a[i] = a_str[i] - '0';
    for (int i = 0; i < b_size; ++i)
        b[i] = b_str[i] - '0';

    int sum[100]; // Assuming the sum will not exceed 100 digits
    int topa = a_size - 1;
    int topb = b_size - 1;
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
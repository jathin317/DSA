#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cout << "Enter a string\n";
    cin >> str;
    char stack[50];
    int top = 0;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        stack[top] = str[i];
        top++;
    }
    cout << "Reversed string: ";
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i];
    }
    cout << endl;
}

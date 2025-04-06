#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string\n";
    cin >> str;
    stack<char> s;
    for (char ch : str)
    {
        s.push(ch);
    }
    cout << "Reversed string: ";
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

/*
Sample Output:

Enter a string
hello
Reversed string: olleh
*/

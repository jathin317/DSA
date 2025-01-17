#include <iostream>
#include <stack>
using namespace std;
int precedence(char a)
{
    if (a == '(' || a == ')')
    {
        return 3;
    }
    else if (a == '^')
    {
        return 2;
    }
    else if (a == '/' || a == '*')
    {
        return 1;
    }
    else if (a == '+' || a == '-')
    {
        return 0;
    }
    return 4;
}
int main()
{
    string infix;
    char result[100];
    stack<char> s;
    cout << "Enter the infix expression" << endl;
    cin >> infix;
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z'))
        {
            result[j++] = infix[i++];
        }
        else if (s.empty())
        {
            s.push(infix[i++]);
        }
        else
        {
            if (precedence(infix[i]) >= precedence(s.top()))
            {
                result[j++] = s.top();
                s.pop();
            }
            else
            {
                s.push(infix[i++]);
            }
        }
    }
    while (!s.empty())
    {
        result[j++] = s.top();
        s.pop();
    }
    result[j] = '\0';
    for (int k = 0; k <= j; k++)
    {
        cout << result[k];
    }
    cout << endl;
}

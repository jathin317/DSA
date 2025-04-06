#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char a)
{
    if (a == '^')
    {
        return 3;
    }
    else if (a == '/' || a == '*')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string infix;
    cout << "Enter the expression: ";
    cin >> infix;

    stack<char> s;
    string result;

    for (int i = 0; i < (int)infix.length(); i++)
    {
        char ch = infix[i];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            result += ch;
        }

        else if (ch == '(')
        {
            s.push(ch);
        }

        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                result += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
        }

        else
        {
            while (!s.empty() && precedence(s.top()) >= precedence(ch))
            {
                result += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }

    cout << "Postfix expression: " << result << endl;
    return 0;
}

/*
Sample Output:

Enter the expression: (A+B)*C
Postfix expression: AB+C*
*/

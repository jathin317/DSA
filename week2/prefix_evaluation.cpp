#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    int op1, op2;
    string exp;
    cout << "Enter the prefix expression\n";
    cin >> exp;
    stack<char> s;
    int i = exp.length() - 1;
    while (i != -1)
    {
        if (exp[i] > '0' && exp[i] < '9')
        {
            s.push(exp[i] - '0');
        }
        else
        {
            if (exp[i] == '+')
            {
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push(op1 + op2);
            }
            else if (exp[i] == '-')
            {
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push(op1 - op2);
            }
            else if (exp[i] == '*')
            {
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push(op1 * op2);
            }
            else if (exp[i] == '/')
            {
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push(op1 / op2);
            }
            else if (exp[i] == '^')
            {
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                int r = 1;
                for (int j = 1; j <= op2; j++)
                {
                    r = r * op1;
                }
                s.push(r);
            }
        }
        i--;
    }
    int result = s.top();
    s.pop();
    cout << result << endl;
}
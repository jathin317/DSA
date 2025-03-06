#include <iostream>
#include <string>
#include <stack>
#include <cmath> // For pow function
using namespace std;

int main()
{
    int op1, op2;
    string exp;
    cout << "Enter the prefix expression\n";
    cin >> exp;
    stack<int> s;
    int i = exp.length() - 1;
    while (i != -1)
    {
        if (isdigit(exp[i]))
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
                s.push(pow(op1, op2));
            }
        }
        i--;
    }
    int result = s.top();
    s.pop();
    cout << result << endl;
    return 0;
}
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string infix;
    cout<<"Enter the infix expression: ";
    cin>>infix;
    string result="";
    string stack="";
    int n=infix.length();
    for(int i=0;i<n;i++)
    {
        if(infix[i]>='A' && infix[i]<='Z')
        {
            result+=infix[i];
        }
        else if(infix[i]=='(')
        {
            stack+=infix[i];
        }
        else if(infix[i]==')')
        {
            while(stack[stack.length()-1]!='(')
            {
                result+=stack[stack.length()-1];
                stack.pop_back();
            }
            stack.pop_back();
        }
        else
        {
            while(stack.length()>0 && stack[stack.length()-1]!='(' && infix[i]<=stack[stack.length()-1])
            {
                result+=stack[stack.length()-1];
                stack.pop_back();
            }
            stack+=infix[i];
        }
    }
}
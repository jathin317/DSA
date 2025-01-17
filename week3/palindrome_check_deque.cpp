#include<iostream>
using namespace std;
int  main()
{
	char queue[50];
	int f=0,r=0;
	int c;
	cout<<"Enter the string: ";
	while((c=getchar())!='\n')
	{
		queue[r++]=c;
	}
	int palindrome=1;
	while(f != r)
	{
		if(queue[f++]!=queue[r--])
		{
			palindrome=0;
			break;
		}
	}
	if(palindrome==1)
	{
		cout<<"It is a palindrome string\n";
	}
	else if(palindrome==0)
		cout<<"It is not a palindrome string\n";
}



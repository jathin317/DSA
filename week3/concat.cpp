#include <iostream>
using namespace std;
int main()
{
	char queue1[10];
	int f1 = -1;
	int r1 = -1;
	char queue2[10];
	int f2 = -1;
	int r2 = -1;
	cout << "Enter first string: ";
	int c;
	f1 = r1 = 0;
	while ((c = getchar()) != '\n')
	{
		queue1[r1++] = c;
	}
	cout << "Enter second string: ";
	f2 = r2 = 0;
	while ((c = getchar()) != '\n')
	{
		queue2[r2++] = c;
	}
	cout << "Concatinated string: ";
	while (f1 != r1)
	{
		cout << queue1[f1++];
	}
	while (f2 != r2)
	{
		cout << queue2[f2++];
	}
	cout << endl;
}

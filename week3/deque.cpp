#include <iostream>
using namespace std;
#define N 5
int deque[N];
int f = -1, r = -1;
void enqueuefront(int x)
{
	if ((f == r + 1) || (f == 0 && r == N - 1))
		cout << "Queue is full\n";
	else if (f == -1 && r == -1)
	{
		f = r = 0;
		deque[f] = x;
	}
	else if (f == 0)
	{
		f = N - 1;
		deque[f] = x;
	}
	else
	{
		f--;
		deque[f] = x;
	}
}
void enqueuerear(int x)
{
	if ((f == r + 1) || (f == 0 && r == N - 1))
	{
		cout << "Queue full\n";
	}
	else if (f == -1 && r == -1)
	{
		f = r = 0;
		deque[r] = x;
	}
	else if (r == N - 1)
	{
		r = 0;
		deque[r] = x;
	}
	else
	{
		r++;
		deque[r] = x;
	}
}
void display()
{
	int i = f;
	if (f == -1 && r == -1)
	{
		cout << "Empty\n";
	}
	else
		while (i != r)
		{
			cout << deque[i] << " ";
			i = (i + 1) % N;
		}
	cout << deque[r] << endl;
}
void dequeuefront()
{
	if (f == -1 && r == -1)
		cout << "Empty\n";
	else if (f == r)
		f = r - 1;
	else if (f == N - 1)
		f = 0;
	else
		f++;
}
void dequeuerear()
{
	if (f == -1 && r == -1)
		cout << "Empty\n";
	else if (f == r)
		f = r = -1;
	else if (r == 0)
		r = N - 1;
	else
		r--;
}
int main()
{
	char ch;

	while (1)
	{
		cout << "♾️ MENU♾️\n1. enqueue at rear\n2. enqueue at front\n3. dequeue at front\n4. dequeue at rear\n5. display\n6. EXIT\n";
		cout << "Enter the choice: ";
		cin >> ch;
		int x;
		switch (ch)
		{
		case '1':
			cout << "Enter the number: ";
			cin >> x;
			enqueuerear(x);
			break;
		case '2':
			cout << "Enter the number: ";
			cin >> x;
			enqueuefront(x);
			break;
		case '3':
			dequeuefront();
			break;
		case '4':
			dequeuerear();
			break;
		case '5':
			display();
			break;
		case '6':
			cout << "Exiting\n";
			return 0;
		default:
			cout << "Invalid input! Try again\n";
		}
	}
}

#include <iostream>
#include <queue>
using namespace std;
void removeNegativeIntegers(queue<int> &q)
{
    queue<int> Queue;

    while (!q.empty())
    {
        int element = q.front();
        q.pop();

        if (element >= 0)
        {
            Queue.push(element);
        }
    }

    q = Queue;
}

int main()
{
    queue<int> q;

    int c;
    cout << "Press Q to stop taking input\n";
    while (cin >> c && c != 'Q')
    {
        q.push(c);
    }

    cout << "Original queue: ";
    queue<int> displayQueue = q;
    while (!displayQueue.empty())
    {
        cout << displayQueue.front() << " ";
        displayQueue.pop();
    }
    cout << endl;

    removeNegativeIntegers(q);

    cout << "Modified queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

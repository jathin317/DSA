/*Given two values X and Y you need to convert X and Y by performing various steps. In a step you can either multiply 2 to the value or subtract 1 from it.
X=2,Y=1
Step1: Multiply by 2
         2 x 2 = 4
Step2: Multiply by 2
        4 x 2 = 8
Step3: Subtract 1
        8-1=7
*/
#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cout << "Enter the value of x and y: ";
    cin >> x >> y;
    while (x != y)
    {
        if (x < y)
        {
            x = x * 2;
            cout << "Step 1: ";
            cout << "X = " << x << ", Y = " << y << endl;
        }
        else
        {
            x = x - 1;
            cout << "Step 2: ";
            cout << "X = " << x << ", Y = " << y << endl;
        }
    }
    return 0;
}

/*
Output:
Enter the value of x and y: 2 7
Step 1: X = 4, Y = 7
Step 1: X = 8, Y = 7
Step 2: X = 7, Y = 7
*/
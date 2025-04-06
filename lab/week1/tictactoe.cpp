#include <iostream>
using namespace std;

void printBoard(char a[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << a[i][j];
            if (j < 2)
                cout << " |";
        }
        cout << endl;
        if (i < 2)
            cout << "---|---|---" << endl;
    }
}

char rowcheck(char a[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != ' ')
        {
            return a[i][0];
        }
    }
    return ' ';
}

char colcheck(char a[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] != ' ')
        {
            return a[0][i];
        }
    }
    return ' ';
}

char diacheck(char a[3][3])
{
    if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != ' ')
    {
        return a[0][0];
    }
    if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] != ' ')
    {
        return a[0][2];
    }
    return ' ';
}

int main()
{
    int i, j;
    char player = 'x';
    int draw = 0; // Initialize draw counter
    char a[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    printBoard(a); // Print initial empty board

    while (1)
    {
        cout << "Enter the position: ";
        cin >> i >> j;
        if (i < 3 && j < 3 && i >= 0 && j >= 0 && a[i][j] == ' ')
        {
            a[i][j] = player;
            draw++;        // Increment draw counter
            printBoard(a); // Print updated board
        }
        else
        {
            cout << "Invalid input\n";
            continue;
        }
        if (rowcheck(a) != ' ' || colcheck(a) != ' ' || diacheck(a) != ' ')
        {
            cout << "player " << player << " wins\n";
            break;
        }
        if (draw == 9) // Check if all positions are filled
        {
            cout << "The game is a tie\n";
            break;
        }
        player = (player == 'x') ? 'o' : 'x';
        continue;
    }
}

/*
Sample Output:

   |   |
---|---|---
   |   |
---|---|---
   |   |

Enter the position: 0 0
 x |   |
---|---|---
   |   |
---|---|---
   |   |

Enter the position: 1 1
 x |   |
---|---|---
   | o |
---|---|---
   |   |

Enter the position: 0 1
 x | x |
---|---|---
   | o |
---|---|---
   |   |

Enter the position: 2 2
 x | x |
---|---|---
   | o |
---|---|---
   |   | o

Enter the position: 0 2
 x | x | x
---|---|---
   | o |
---|---|---
   |   | o

player x wins
*/

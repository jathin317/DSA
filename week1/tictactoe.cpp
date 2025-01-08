#include <iostream>
using namespace std;

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
    char a[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            cout << "- ";
        }
        cout << endl;
    }
    while (1)
    {
        cout << "Enter the position: ";
        cin >> i >> j;
        if (i < 3 && j < 3 && i >= 0 && j >= 0 && a[i][j] == ' ')
        {
            a[i][j] = player;
            draw++; // Increment draw counter
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    cout << a[k][l] << " ";
                }
                cout << "\n";
            }
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

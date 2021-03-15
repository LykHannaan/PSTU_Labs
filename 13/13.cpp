#include <iostream>
#include <windows.h>

using namespace std;

int board[8][8];
int res_count = 1; 

void showBoard()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
            if (board[i][j] == 1)
                cout << "Q ";        
            else
                cout << ". ";

        cout << '\n';
    }
}

bool tryQueen(int i, int j)
{
    for (int k = 0; k < i; ++k)
    {
        if (board[k][j]) return false;
    }

    for (int k = 1; k <= i && j - k >= 0; ++k)
    {
        if (board[i - k][j - k]) return false;
    }

    for (int k = 1; k <= i && j + k < 8; k++)
    {
        if (board[i - k][j + k]) return false;
    }
    return true;
}

void setQueen(int i) 
{
    if (i == 8)
    {
        showBoard();
        cout << "Результат №" << res_count++ << "\n\n";
        return; 
    }
    for (int k = 0; k < 8; ++k)
    {
        if (tryQueen(i, k))
        {
            board[i][k] = 1;
            setQueen(i + 1);
            board[i][k] = 0;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setQueen(0);

    return 0;
}

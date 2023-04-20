#include <bits/stdc++.h>
using namespace std;

bool checksafety(int row, int col, vector<vector<char>> &chessboard, int n)
{

    if (col == 0)
    {
        return true;
    }
    for (int i = col; i >= 0; i--)
    {
        if (chessboard[row][i] == 'Q')
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (chessboard[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row, j = col; i <= n - 1 && j >= 0; i++, j--)
    {
        if (chessboard[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void solverans(int column, int n, vector<vector<char>> &chessboard, vector<vector<vector<char>>> &ans)
{

    if (column == n)
    {
        ans.push_back(chessboard);
        return;
    }

    else
    {

        for (int i = 0; i < n; i++)
        {
            if (checksafety(i, column, chessboard, n))
            {
                chessboard[i][column] = 'Q';
                solverans(column + 1, n, chessboard, ans);

                chessboard[i][column] = '.';
            }
        }
    }
}

vector<vector<string>> nqueens(int n){
    vector<vector<char>> chessboard;
    vector<vector<vector<char>>> ans;
    vector<vector<string>> sol;

    vector<char> a;
    for (int j = 0; j < n; j++)
    {
        a.push_back('.');
    }
    for (int i = 0; i < n; i++)
    {
        chessboard.push_back(a);
    }

    solverans(0, n, chessboard, ans);

    for (auto k : ans)

    {
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            string temp2 = "";
            for (int j = 0; j < n; j++)
            {
                temp2 = temp2 + k[i][j];
            }
            temp.push_back(temp2);
            cout << endl;
        }
        sol.push_back(temp);
    }

    return sol;
}

int main()
{
    int n = 5;

    vector<vector<char>> chessboard;
    vector<vector<vector<char>>> ans;
    vector<vector<string>> sol;

    vector<char> a;
    for (int j = 0; j < n; j++)
    {
        a.push_back('.');
    }
    for (int i = 0; i < n; i++)
    {
        chessboard.push_back(a);
    }

    solverans(0, n, chessboard, ans);

    for (auto k : ans)

    {
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            string temp2 = "";
            for (int j = 0; j < n; j++)
            {
                temp2 = temp2 + k[i][j];
            }
            temp.push_back(temp2);
            cout << endl;
        }
        sol.push_back(temp);
    }

    return 0;
}


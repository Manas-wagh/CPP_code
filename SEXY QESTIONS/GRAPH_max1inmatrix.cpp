
// Given a binary matrix A of size N x M.

//  Cells which contain 1 are called filled cell and cell that contain 0 are called empty cell.

// Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.

// If one or more filled cells are also connected, they form a region. Find the length of the largest region.

#include <bits/stdc++.h>
using namespace std;

int dfs(int row, int col, vector<vector<bool>> &vis, int maxRow, int maxCol, vector<vector<int>> &A)
{
    vis[row][col] = 1;
    int regionSize = 1;
    for (int r = -1; r <= 1; r++)
    {
        for (int c = -1; c <= 1; c++)
        {
            int newRow = row + r;
            int newCol = col + c;
            if (newRow < maxRow && newRow >= 0 && newCol < maxCol && newCol >= 0 && A[newRow][newCol] == 1 && !vis[newRow][newCol])
            {
                regionSize += dfs(newRow, newCol, vis, maxRow, maxCol, A);
            }
        }
    }
    return regionSize;
}

int solve(vector<vector<int>> &A)
{
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<bool>> vis(A.size(), vector<bool>(A[0].size()));
    int maxSize = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (A[i][j] == 1 && !vis[i][j])
            {
                maxSize = max(maxSize, dfs(i, j, vis, rows, cols, A));
            }
        }
    }
    return maxSize;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
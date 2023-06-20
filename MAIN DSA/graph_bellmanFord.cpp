#include <bits/stdc++.h>
using namespace std;

vector<int> bellford(vector<vector<int>> &matrix, int n)
{
    vector<int> dist(n, INT32_MAX);
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[j] > dist[i] + matrix[i][j])
            {
                dist[j] = dist[i] + matrix[i][j];
            }
        }
    }
    return dist;
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
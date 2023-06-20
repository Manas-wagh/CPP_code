#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool bfs(vector<vector<int>> &dist, int n, int m, int x, int y)
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    q.push({x, y});
    dist[x][y] = 0;
    while (q.empty() == false)
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        visited[a][b] = true;
        for (int i = 0; i < 8; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == false)
            {
                q.push({nx, ny});
                dist[nx][ny] = min(dist[nx][ny], dist[a][b] + 1);
            }
        }
    }
}

int knight(int n, int m, int x, int y, int fx, int fy)
{
    vector<vector<int>> dist(n, vector<int>(m, INT32_MAX));
    bfs(dist, n, m, x - 1, y - 1);
    return dist[fx - 1][fy - 1];
}

int main()
{

    cout << knight(8, 8, 1, 1, 8, 8);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &list, vector<int> &ans, int src, bool visited[])
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (q.empty() == false)
    {
        int curr = q.front();
        ans.push_back(curr);
        q.pop();
        for (auto it : list[curr])
        {
            if (visited[it] == false)
            {
                q.push(it);
                visited[it] = true;
            }
        }
    }
}

void dfs(vector<vector<int>> &list, vector<int> &ans, int src, vector<bool> &visited)
{
    visited[src] = true;
    ans.push_back(src);
    for (auto it : list[src])
    {
        if (visited[it] == false)
        {
            dfs(list, ans, it, visited);
        }
    }
}

vector<int> djstra(vector<vector<int>> &list, int src, int n)
{
    vector<bool> visited(n, false);
    vector<int> dist(n, INT32_MAX);

    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minvtx = -1;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == false && (minvtx == -1 || dist[j] < dist[minvtx]))
            {
                minvtx = j;
            }
        }
        visited[minvtx] = true;
        for (auto it : list[minvtx])
        {
            if (visited[it] == false && dist[it] > dist[minvtx] + list[minvtx][it])
            {
                dist[it] = dist[minvtx] + list[minvtx][it];
            }
        }
    }
    return dist;
}
int MST(vector<vector<int>> &matrix, int n)
{
    bool inMST[n] = {false};
    int currdist[n] = {INT32_MAX};
    currdist[0] = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if (inMST[j] == false && (u == -1 || currdist[j] < currdist[u]))
            {
                u = j;
            }
        }
        inMST[u] = true;
        res += currdist[u];
        for (int j = 0; j < n; j++)
        {
            if (inMST[j] == false && matrix[u][j] != 0)
            {
                currdist[j] = min(currdist[j], matrix[u][j]);
            }
        }
    }
    return res;
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
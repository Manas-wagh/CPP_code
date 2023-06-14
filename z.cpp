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

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;



void addedge(vector<vector<int>> &v, int a, int b)
{
    v[a].push_back(b);
    v[b].push_back(a);
    // cout << "done!" << endl;
}

void printg(vector<vector<int>> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}


// sir method

void shortest_dist(vector<vector<int>> &v, int vtx, int src)
{
    bool visited[vtx + 1];
    for (int i = 0; i < vtx; i++)
    {
        visited[i] = false;
    }
    int dist[vtx + 1];
    for (int i = 0; i < vtx; i++)
    {
        dist[i] = -1;
    }
    dist[src] = 0;
    visited[src] = true;
    queue<int> que;
    que.push(src);
    while (que.empty() == false)
    {
        int u = que.front();

        que.pop();
        for (int st : v[u])
        {
            if (visited[st] == false)
            {
                visited[st] = true;
                que.push(st);
                dist[st] = dist[u] + 1;
            }
        }
    }
    for (int i = 0; i < vtx; i++)
    {
        if (dist[i] != -1)
        {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}
int main()
{
    int n, cnt;
    cin >> n;
    vector<vector<int>> v(n);
    addedge(v, 0, 1);
    addedge(v, 0, 2);
    addedge(v, 1, 2);
    addedge(v, 1, 3);
    addedge(v, 2, 3);
    addedge(v, 3, 4);
    // bfs_shrt_dist(v, n, 0);
    shortest_dist(v, n, 0);
    return 0;
}
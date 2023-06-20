#include <bits/stdc++.h>
using namespace std;

//----> undirected graph <----//
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

//-------------------------------------------------->graph traversal mechanisms<----------------------------------------------------------//
//---->here we print interst node first, the immediate adj nodes--then their adj and so on without repetation of nodes

//--(1).------->BREADTH FIRST SEARCH BFS...
/// there are various methods
//
// 1. given undirected graph and a source vertex..and perform bfs from source vertex

void bfs_s(vector<vector<int>> &v, int vtx, int src)
{
    bool visited[vtx + 1];
    for (int i = 0; i < vtx; i++)
    {
        visited[i] = false;
    }
    visited[src] = true;
    queue<int> que;
    que.push(src);

    while (que.empty() == false)
    {
        int u = que.front();
        cout << u << " ";
        que.pop();
        for (int st : v[u])
        {
            if (visited[st] == false)
            {
                visited[st] = true;
                que.push(st);
            }
        }
    }
    cout << endl;
}

// 2. given undirected graph (may be discontinuous) and no source vertex is given, perform bfs..

void bfsref(vector<vector<int>> &v, int src, bool visited[])
{

    visited[src] = true;
    queue<int> que;
    que.push(src);

    while (que.empty() == false)
    {
        int u = que.front();
        cout << u << " ";
        que.pop();
        for (int st : v[u])
        {
            if (visited[st] == false)
            {
                visited[st] = true;
                que.push(st);
            }
        }
    }
}
int bfs_m(vector<vector<int>> &v, int vtx)
{
    int cnt = 0;
    bool visited[vtx + 1];
    for (int i = 0; i < vtx; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < vtx; i++)
    {
        if (visited[i] == false)
        {
            bfsref(v, i, visited);
            cnt++;
        }
    }
    cout << endl;
    return cnt;
}

//--(1).------->DEPTH FIRST SEARCH DFS...
/// there are various methods
//
// 1. given undirected and connected graph..and perform dfs from given source

void DFSref(vector<vector<int>> &v, int src, vector<bool> &visited)
{
    visited[src] = true;
    cout << src << " ";
    for (int u : v[src])
    {
        if (visited[u] == false)
        {
            DFSref(v, u, visited);
        }
    }
}
void DFS(vector<vector<int>> &v, int vtx, int src)
{
    vector<bool> visited(vtx);
    for (int i = 0; i < vtx; i++)
    {
        visited[i] = false;
    }
    DFSref(v, src, visited);
}

// 2. given undirected and dis-connected graph...

void DFS_m(vector<vector<int>> &v, int vtx, int src)
{
    vector<bool> visited(vtx);
    for (int i = 0; i < vtx; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < vtx; i++)
    {
        if (visited[i] == false)
        {
            DFSref(v, i, visited);
        }
    }
}

//---<> detecting cycle in an undirected disconnected graph.....

bool DFSref_cycle(vector<vector<int>> &v, int src, vector<bool> &visited, int parent)
{
    visited[src] = true;

    for (int u : v[src])
    {
        if (visited[u] == false)
        {
            if (DFSref_cycle(v, u, visited, src) == true)
            {
                return true;
            }
        }
        else if (u != parent)
        {
            return true;
        }
    }
    return false;
}

bool DFS_m_cycle_det(vector<vector<int>> &v, int vtx)
{

    vector<bool> visited(vtx);
    for (int i = 0; i < vtx; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < vtx; i++)
    {
        if (visited[i] == false)
        {
            if (DFSref_cycle(v, i, visited, -1) == true)
            {
                return true;
            }
        }
    }
    return false;
}

//---<> detecting cycle in an directed disconnected graph.....

bool directed_cyl_ref(vector<vector<int>> &v, int src, vector<bool> &visited, vector<bool> &inque)
{
    visited[src] = true;
    inque[src] = true;
    for (int u : v[src])
    {
        if (visited[u] == false && directed_cyl_ref(v, u, visited, inque))
        {
            return true;
        }
        else if (inque[u] == true)
        {
            return true;
        }
    }
    inque[src] = false;
    return false;
}

bool directed_cyl_m(vector<vector<int>> &v, int vtx)
{
    vector<bool> visited(vtx, false);
    vector<bool> inque(vtx, false);
    for (int i = 0; i < vtx; i++)
    {
        if (visited[i] == false)
        {
            if (directed_cyl_ref(v, i, visited, inque) == true)
            {
                return true;
            }
        }
    }
    return false;
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

    // bfs_s(v, n, 0);

    addedge(v, 5, 4);
    // addedge(v, 0, 4);
    // printg(v, n);

    // cnt = bfs_m(v, n);
    // cout << "number of islands are " << cnt;

    // cout << endl;
    // DFS(v, n, 0);

    cout << endl;
    DFS_m(v, n, 0);
    cout << endl;

    // cycle detection

    if (DFS_m_cycle_det(v, n) == true)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}
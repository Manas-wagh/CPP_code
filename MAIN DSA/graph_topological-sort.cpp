#include <bits/stdc++.h>
using namespace std;

// in this sorting we call vertex as JOBS ans edges as DEPENDENCIES.
//....in this job(i) must be printed before all the jobs in his dependencies...printing order of dependencies dosent matter
//....ie all the vertices with 0 indegree should be printed first ...
//....after printing it...decrease 1 indegree from all the dependent vertices it has.
//....again do the same.
// works on acylic only
// but is used to detect cycle

//----------->creating directed graph<-----------------//

void addedge(vector<vector<int>> &v, vector<int> &indegree, int from, int to)
{
    v[from].push_back(to);
    indegree[to]++;
}
void printg(vector<vector<int>> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << i << " to " << v[i][j] << endl;
        }
    }
}

// kahns algorithm

void topo_khan(vector<vector<int>> &v, vector<int> indegree, int vtx)
{
    queue<int> q;
    for (int i = 0; i < v.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int x : v[u])
        {
            indegree[x] = indegree[x] - 1;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
}

// detecting cycle using kahn algo

void topo_khan_detcyl(vector<vector<int>> &v, vector<int> indegree, int vtx)
{
    queue<int> q;
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int x : v[u])
        {
            indegree[x] = indegree[x] - 1;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
        count++;
    }
    if (count == v.size())
    {
        cout << "no cycle" << endl;
    }
    else
    {
        cout << "yes there is cycle" << endl;
    }
}

// DFS method

void topo_dfs_ref(vector<vector<int>> &v, stack<int> &st, vector<bool> &visited, int src)
{

    visited[src] = true;
    for (int u : v[src])
    {
        if (visited[u] == false)
        {
            topo_dfs_ref(v, st, visited, u);
            st.push(u);
        }
    }
}

void topo_dfs(vector<vector<int>> &v, int vtx)
{
    stack<int> st;
    vector<bool> visited(vtx);
    for (int i = 0; i < vtx; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < vtx; i++)
    {
        if (visited[i] == false)
        {
            topo_dfs_ref(v, st, visited, i);
            st.push(i);
        }
    }
    while (!st.empty())
    {
        int p = st.top();
        cout << p << " ";
        st.pop();
    }
}

int main()
{
    int n, cnt;
    cin >> n;
    vector<vector<int>> v(n);
    vector<int> indegree(n);
    for (int i = 0; i < n; i++)
    {
        indegree.push_back(0);
    }

    addedge(v, indegree, 0, 1);
    addedge(v, indegree, 0, 2);
    addedge(v, indegree, 1, 2);
    addedge(v, indegree, 2, 3);
    addedge(v, indegree, 3, 1);
    // addedge(v, indegree, 5, 4);

    printg(v, n);
    // cout << endl;
    // topo_khan(v, indegree, n);

    // cout << endl;
    // topo_khan_detcyl(v, indegree, n);

    topo_dfs(v, n);
    return 0;
}
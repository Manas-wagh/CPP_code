#include <bits/stdc++.h>
using namespace std;

// using kahns algorithmn

void addedge(vector<vector<int>> &v, vector<int> &indegree, int from, int to)
{
    v[from].push_back(to);
    indegree[to]++;
}
void creategraphw(vector<vector<int>> &matrix, int a, int b, int weight)
{
    matrix[a][b] = weight;
}
vector<int> topo_khan(vector<vector<int>> &v, vector<int> &indegree, int vtx)
{
    queue<int> q;
    vector<int> output;
    int c = 0;
    for (int i = 0; i < vtx; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        output[c] = u;
        c++;
        q.pop();

        for (int x : v[u])
        {
            indegree[x] = indegree[x] - 1;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    return output;
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

vector<int> shortest_DAG(vector<vector<int>> &v, vector<int> &indegree, vector<vector<int>> &matrix, int vtx, int src)
{
    cout << 1;
    vector<int> distance(vtx);
    for (int i = 0; i < vtx; i++)
    {
        distance.push_back(1000);
    }

    distance[src] = 0;
    vector<int> ans;
    ans = topo_khan(v, indegree, vtx);
    for (int i : ans)
    {
        for (int u : v[i])
        {
            if (distance[u] > distance[i] + matrix[i][u])
            {
                distance[u] = distance[i] + matrix[i][u];
            }
        }
    }
    return distance;
}
int main()
{
    int n;

    cin >> n;
    vector<vector<int>> v(n);
    vector<int> indegree(n);
    for (int i = 0; i < n; i++)
    {
        indegree.push_back(0);
    }
    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i].push_back(0);
        }
    }
    vector<int> dist;

    addedge(v, indegree, 0, 1);
    addedge(v, indegree, 0, 2);
    // addedge(v, indegree, 1, 2);
    addedge(v, indegree, 2, 3);
    addedge(v, indegree, 1, 3);
    cout << 4;
    creategraphw(matrix, 0, 1, 5);
    creategraphw(matrix, 0, 2, 6);
    // creategraphw(matrix, 1, 2, 15);
    creategraphw(matrix, 1, 3, 10);
    creategraphw(matrix, 2, 3, 8);

    cout << 1;

    dist = shortest_DAG(v, indegree, matrix, n, 0);

    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }

    // dist = topo_khan(v, indegree, n);

    return 0;
}
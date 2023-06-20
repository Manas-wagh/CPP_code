#include <bits/stdc++.h>
using namespace std;

const int maxn = 100009;
vector<int> adj[maxn];
long long s;
long long maxe;
const int mod = 1e9 + 7;

int dfs(int u, int p, vector<int> &A)
{
    long long sum = A[u - 1];
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        sum += dfs(v, u, A);
    }
    long long res = ((sum) * ((s - sum)));
    maxe = max(maxe, res);
    return sum;
}

int deleteEdge(vector<int> &A, vector<vector<int>> &B)
{

    s = 0;    // total sum of tree
    maxe = 0; // maximum product

    // clearing the adjacency list
    for (int i = 0; i <= A.size(); i++)
        adj[i].clear();

    // Calculating sum of weights of all nodes
    for (int a : A)
        s += a;

    // Creating tree
    for (auto &it : B)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    dfs(1, 0, A);

    return maxe % mod;
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
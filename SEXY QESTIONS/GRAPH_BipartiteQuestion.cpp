// There are A people numbered 1 to A in a football academy.

// The coach of the academy wants to make two teams (not necessary of equal size) but unfortunately, not all people get along, and several refuse to be put on the same team as that of their enemies.

// Given a 2-D array B of size M x 2 denoting the enemies i.e B[i][0] and B[i][1] both are enemies of each other.

// Return 1 if it possible to make exactly two teams else return 0.

// EXPLANATION

// Create a graph such that there is a edge between each pair of enemies.

// We need to find that the above graph is bipartite or not. Check whether the graph is 2-colorable or not

// We can do that by running dfs and using an auxilary array col to store the assigned col of the node.

// If we can color the graph with two color such that no two enemies have same color then only we can create two teams.

// Note: Since the graph can be disconnected so run dfs on each component.

#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int ans, vis[100005];
void dfs(int i)
{
    for (auto j : g[i])
    {
        if (!vis[j])
        {
            vis[j] = 3 - vis[i];
            dfs(j);
        }
        else if (vis[i] == vis[j])
            ans = 0;
    }
}
int solve(int A, vector<vector<int>> &B)
{
    for (auto i : B)
    {
        g[i[0]].push_back(i[1]);
        g[i[1]].push_back(i[0]);
    }
    int ret = 1;
    for (int i = 1; i <= A; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        ans = 1;
        dfs(i);
        ret &= ans;
    }
    for (int i = 1; i <= A; i++)
    {
        g[i].clear();
        vis[i] = 0;
    }
    return ret;
}

// ques 2 : find if graph is bipartite

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> vis(n, -1);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == -1)
            {
                vis[i] = 0;
                q.push(i);
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for (int v : graph[u])
                    {
                        if (vis[v] == -1)
                        {
                            vis[v] = vis[u] ^ 1;
                            q.push(v);
                        }
                        else if (vis[v] == vis[u])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
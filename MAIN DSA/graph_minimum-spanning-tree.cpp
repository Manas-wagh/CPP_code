#include <bits/stdc++.h>
using namespace std;

//-->SPANNING TREE is a tree ie it dosent have any cycle.
// ie if there are v vertices then we want v-1 edges

// spanning tree is something which is defined for unweighted graph
// in weighted graph we have to find all spanning tree and take the one with minimum weight

/////////---------------------------> ALGOS TO FIND MINIMUM SPANNING TREE (MST) <-------------------------------------//////
// these algos work only on undirected weighted connected

//---->PRIMS ALGO
// we take any one v and then take e with least weight connecting it...now the both connected v act as graph
// and we now take that e which has least weight in all edges that connect this graph....and so on

// creating weighted graph

void creategraphw(vector<vector<int>> &matrix, int a, int b, int weight)
{
    matrix[a][b] = weight;
    matrix[b][a] = weight;
}

int MST(vector<vector<int>> &matrix, int vtx)
{
    int min_weight[vtx];
    fill(min_weight, min_weight + vtx, INT_MAX);
    bool present[vtx] = {false};
    int sum = 0;
    min_weight[0] = 0;

    for (int j = 0; j < vtx; j++)
    {
        int u = -1;
        for (int i = 0; i < vtx; i++)
        {
            if (!present[i] && (u == -1 || min_weight[i] < min_weight[u]))
            {
                u = i;
            }
        }
        present[u] = true;
        sum = sum + min_weight[u];
        for (int i = 0; i < vtx; i++)
        {
            if (matrix[u][i] != 0 && !present[i])
            {
                min_weight[i] = min(matrix[u][i], min_weight[i]);
            }
        }
    }
    return sum;
}

// NLOGN ka algo, using minheap and adj list;
// refer gfg if need

int sexyMST(vector<vector<int>> &edge, int vtx)
{
    vector<vector<pair<int, int>>> list(vtx);
    for (int i = 0; i < edge.size(); i++)
    {
        list[edge[i][0]].push_back(make_pair(edge[i][1], edge[i][2]));
        list[edge[i][1]].push_back(make_pair(edge[i][0], edge[i][2]));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bool visited[vtx] = {false};
    int dist[vtx] = {INT32_MAX};
    int res = 0;
    //
    pq.push({0, 0});
    dist[0] = 0;
    while (pq.empty() == false)
    {
        int curr = pq.top().second;
        int addwt = pq.top().first;
        pq.pop();
        if (visited[curr] == true)
        {
            continue;
        }
        visited[curr] = true;
        res = res + addwt;
        for (auto i : list[curr])
        {
            int v = i.first;
            int wt = i.second;
            if (visited[v] == false && dist[v] > wt)
            {
                dist[v] = wt;
                pq.push({dist[v], v});
            }
        }
    }
    return res;
}

int main()
{
    int vtx;
    cin >> vtx;

    vector<vector<int>> matrix(vtx);
    for (int i = 0; i < vtx; i++)
    {
        for (int j = 0; j < vtx; j++)
        {
            matrix[i].push_back(0);
        }
    }

    creategraphw(matrix, 0, 1, 5);
    creategraphw(matrix, 0, 2, 6);
    creategraphw(matrix, 2, 1, 15);
    creategraphw(matrix, 3, 1, 10);
    creategraphw(matrix, 2, 3, 8);

    return 0;
}
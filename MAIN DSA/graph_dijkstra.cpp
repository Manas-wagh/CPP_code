#include <bits/stdc++.h>
using namespace std;
// used to find shortest path btwn source and all other vertex
// take src vertex ..find its adj which is not finalised....relax them...pick up the shortest ...gon on it....repeat

vector<int> dijikstra(vector<vector<int>> &matrix, int vtx, int src)
{
    vector<int> distance(vtx, INT_MAX);
    vector<bool> finalised(vtx, false);
    distance[src] = 0;

    for (int c = 0; c < vtx; c++)
    {
        int u = -1;
        for (int i = 0; i < vtx; i++) // for finding and picking non finalised minimum vertex
        {
            if (!finalised[i] && (u == -1 || distance[i] < distance[u])) // finalised na ho and min ho
            {
                u = i;
            }
        }
        finalised[u] = true;
        for (int i = 0; i < vtx; i++) // for updating minimum distance
        {
            if (!finalised[i] && matrix[u][i] != 0)
            {
                distance[i] = min(distance[i], distance[u] + matrix[u][i]); // making distance min
            }
        }
    }
    return distance;
}

void creategraphw(vector<vector<int>> &matrix, int a, int b, int weight)
{
    matrix[a][b] = weight;
    matrix[b][a] = weight;
}

// ELOGV wala solution

vector<int> sexyMST(vector<vector<int>> &edge, int vtx)
{
    vector<vector<pair<int, int>>> list(vtx);
    for (int i = 0; i < edge.size(); i++)
    {
        list[edge[i][0]].push_back(make_pair(edge[i][1], edge[i][2]));
        list[edge[i][1]].push_back(make_pair(edge[i][0], edge[i][2]));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bool visited[vtx] = {false};
    vector<int> dist(vtx, {INT32_MAX});
    int res = 0;
    //
    pq.push({0, 0});
    dist[0] = 0;
    while (pq.empty() == false)
    {
        int curr = pq.top().second;
        pq.pop();
        if (visited[curr] == true)
        {
            continue;
        }
        visited[curr] = true;
        for (auto i : list[curr])
        {
            int v = i.first;
            int wt = i.second;
            if (visited[v] == false && dist[v] > dist[curr] + wt)
            {
                dist[v] = dist[curr] + wt;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{

    int vtx;
    cin >> vtx;
    vector<int> output(vtx);

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

    output = dijikstra(matrix, vtx, 0);
    for (int j = 0; j < vtx; j++)
    {
        cout << output[j] << " ";
    }

    return 0;
}
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
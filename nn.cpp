#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool bfs(vector<vector<int>> &list, vector<pair<bool, int>> &visited, int src)
    {

        queue<int> q;
        q.push(src);
        visited[src].second = 1;
        while (q.empty() == false)
        {

            int frnt = q.front();
            visited[frnt].first = true;

            q.pop();
            for (auto i : list[frnt])
            {

                if (visited[i].first == false)
                {
                    visited[i].second = 1 ? visited[src].second = 2 : 2;
                    q.push(i);
                }
                else
                {
                    if (visited[i].second == visited[src].second)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &list)
    {
        vector<pair<bool, int>> visited(list.size(), {false, -1});
        for (int i = 0; i < list.size(); i++)
        {

            if (visited[i].first == false)
            {
                if (bfs(list, visited, i) == false)
                {
                    return false;
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

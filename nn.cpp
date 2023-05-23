#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        queue<int> q;
        set<int> s;
        int maxd = 0;
        int mind = 0;
        int mind1 = 0;
        int i = 0;
        bool visited[n + 1] = {false};
        for (int j = 0; j < n; j++)
        {
            // cout << *s.find(arr[i]) << endl;
            if (q.empty())
            {
                q.push(j + 1);
                s.insert(j + 1);
                visited[j + 1] = true;
                i = j;
            }
            else
            {
            }
            if (visited[arr[i]] && arr[i] != q.front() && s.find(arr[i]) != s.end())
            {
                cout << "a ";
                maxd++;
                mind++;
                while (!q.empty())
                {
                    q.pop();
                }
                s.clear();
            }
            else if (visited[arr[i]] && arr[i] == q.front() && s.find(arr[i]) != s.end())
            {
                cout << "b ";
                maxd++;
                if (s.size() == 2)
                {
                    mind++;
                }
                while (!q.empty())
                {
                    q.pop();
                }
                s.clear();
            }
            else if (visited[arr[i]] && s.find(arr[i]) == s.end())
            {
                cout << "c ";
                mind++;
                while (!q.empty())
                {
                    q.pop();
                }
                s.clear();
            }
            else
            {
                cout << "d ";
                q.push(arr[i]);
                s.insert(arr[i]);
                visited[arr[i]] = true;
                i = arr[i] - 1;
            }
        }
        if (mind == 0 || maxd == 1)
        {
            mind1 = maxd;
        }
        cout << mind1 + mind / 2 << " " << maxd << endl;
    }
    return 0;
}
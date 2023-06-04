#include <bits/stdc++.h>
using namespace std;

int diffPossible(const vector<int> &arr, int b)
{
    map<int, set<int>> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i] + b].insert(i);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        auto it = mp.find(arr[i]);
        if (it != mp.end())
        {
            auto pt = it->second.find(i);
            if (pt != it->second.end())
            {
                return 1;
            }
        }
    }
    return 0;
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
#include <bits/stdc++.h>
using namespace std;

bool mycmp(pair<int, int> a, pair<int, int> b)
{
    return (a.second <= b.second);
}

int maxactivity(pair<int, int> arr[], int n)
{
    sort(arr, arr + n, mycmp);
    int prev = 0;
    int res = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].first >= arr[prev].second)
        {
            res++;
            prev = i;
        }
    }
    return res;
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
#include <bits/stdc++.h>
using namespace std;

// first el of pair is value and 2nd is weight

bool mycmp(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return (r1 > r2);
}

double FKnapsack(pair<int, int> arr[], int n, int wt)
{
    double res = 0.0;
    int curr_wt = wt;
    sort(arr, arr + n, mycmp);

    for (int i = 0; i < n; i++)
    {
        if (arr[i].second <= curr_wt)
        {
            res += arr[i].first;
            curr_wt -= arr[i].second;
        }
        else
        {
            res += arr[i].first * ((double)curr_wt / arr[i].second);
            break;
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
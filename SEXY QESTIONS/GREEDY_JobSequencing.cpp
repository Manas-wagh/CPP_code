#include <bits/stdc++.h>
using namespace std;

bool mycmp(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return (r1 > r2);
}

double FKnapsack(pair<int, int> arr[], int n)
{
    double res = 0.0;
    int curr_t = 0;
    sort(arr, arr + n, mycmp);

    for (int i = 0; i < n; i++)
    {
        if (arr[i].second > curr_t)
        {
            res += arr[i].first;
            curr_t++;
        }
        else
        {
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
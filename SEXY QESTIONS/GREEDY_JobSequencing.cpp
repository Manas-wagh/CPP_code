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
    cout << curr_t << endl;
    return res;
}

int main()
{

    int t;
    cin >> t;
    pair<int, int> arr[t];
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    cout << FKnapsack(arr, t);
    return 0;
}
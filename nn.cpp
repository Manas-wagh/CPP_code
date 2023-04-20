#include <bits/stdc++.h>
using namespace std;

int minsquare(int *arr, int n, int value)
{
    int dp[value + 1];
    for (int i = 1; i < value + 1; i++)
    {
        dp[i] = INT16_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i < value + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] <= i)
            {
                if (dp[i - arr[j]] != INT16_MAX)
                {
                    dp[i] = min(dp[i], dp[i - arr[j]] + 1);
                }
            }
        }
    }
    return dp[value];
}

int main()
{
    int val;
    cin >> val;
    int prefix[100];
    for (int i = 0; i < 100; i++)
    {
        prefix[i] = (i + 1) * (i + 1);
    }

    cout << minsquare(prefix, 100, val);

    return 0;
}
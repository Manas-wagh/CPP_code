#include <bits/stdc++.h>
using namespace std;

int minsum(int *arr, int n, int val)
{
    int dp[val + 1];
    for (int i = 1; i < val + 1; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i < val + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] <= i)
            {
                int sr = dp[i - arr[j]];
                if (sr != INT_MAX)
                {
                    dp[i] = min(dp[i], sr + 1);
                }
            }
        }
    }
    return dp[val];
}

int main()
{
    int arr[3] = {1, 2, 3};
    cout << minsum(arr, 3, 5);
    return 0;
}
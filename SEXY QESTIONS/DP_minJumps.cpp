#include <bits/stdc++.h>
using namespace std;

int minjumps(int *arr, int n)
{
    int dp[n];

    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] + j >= i)
            {
                if (dp[j] != 1000)
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }

    return dp[n - 1];
}

int main()
{
    int arr[6] = {2, 3, 1, 4, 10, 1};
    cout << minjumps(arr, 6);
    return 0;
}
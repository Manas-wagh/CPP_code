#include <bits/stdc++.h>
using namespace std;

int coin(int *arr, int n, int wt)
{
    if (wt == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    int res = coin(arr, n - 1, wt);
    if (arr[n] <= wt)
    {
        res = res + coin(arr, n, wt - arr[n]);
    }
    return res;
}

// dp ka soln

int cointab(int *arr, int n, int wt)
{

    int dp[wt + 1][n + 1] = {-1};
    for (int i = 0; i < n + 1; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < wt + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i < wt + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            dp[wt][n] = dp[wt][n - 1];
            if (arr[n] <= wt)
            {
                dp[wt][n] += dp[wt - arr[n]][n];
            }
        }
    }
    return dp[wt][n];
}

int main()
{

    return 0;
}
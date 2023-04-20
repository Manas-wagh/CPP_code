#include <bits/stdc++.h>
using namespace std;

// naive reccursive    2^n time comp

int knapsack(int *val, int *wt, int n, int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    else
    {
        if (wt[n - 1] > W)
        {
            return knapsack(val, wt, n - 1, W);
        }
        else
        
        {
            return max(knapsack(val, wt, n - 1, W), knapsack(val, wt, n - 1, W - wt[n - 1]) + val[n - 1]);
        }
    }
}

// dp solution   n*W time comp

int knapsackdp(int *val, int *wt, int n, int W)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < W + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int val[4] = {10, 40, 30, 50};
    int wt[4] = {5, 4, 6, 3};
    cout << knapsack(val, wt, 4, 10);
    cout << endl;
    cout << knapsackdp(val, wt, 4, 10);
    return 0;
}
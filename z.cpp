#include <bits/stdc++.h>
using namespace std;

int minsum(int *arr, int n, int val)
{
    int dp[val + 1];
    for (int i = 0; i < val + 1; i++)
    {
        dp[i] = 0;
    }

    for (int i = 1; i < val + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
        }
    }
    return dp[val];
}

int SSdp(int *arr, int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < sum + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int profit(int *price, int t)
{

    int a = 1, b = 2;
    int profit = 0;
    while (b <= t - 1)
    {
        if (price[a] <= price[b])
        {
            profit += price[b] - price[a];
            a++;
            b++;
        }
        else
        {
            a = b;
            b++;
        }
    }
    return profit;
}

int main()
{
    int arr[6] = {5};
    cout << SSdp(arr, 1, 1);
    cout << endl;
    int at[7] = {0, 7, 1, 5, 3, 6, 4};
    cout << profit(at, 7);
    return 0;
}
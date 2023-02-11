#include <bits/stdc++.h>
using namespace std;

int code(int *arr, int n, int sum)
{

    if (n == 0 && sum == 0)
    {
        return 0;
    }
    if (n == 0 && sum != 0)
    {
        return 1000;
    }
    if (n != 0 && sum == 0)
    {
        return 0;
    }
    else
    {
        if (arr[n - 1] > sum)
        {
            return code(arr, n - 1, sum);
        }
        else
        {
            return 1 + min(code(arr, n - 1, sum), code(arr, n, sum - arr[n - 1]));
        }
    }
    return 0;
}

int ggg(int *arr, int n, int sum)
{

    int dp[sum + 1][n + 1] = {-1};
    for (int i = 0; i < n + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i < sum + 1; i++)
    {
        dp[i][0] = 10000;
    }
    for (int i = 1; i < sum + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (arr[j - 1] > sum)
            {
                dp[i][j] = dp[i][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - arr[j - 1]][j], dp[i][j - 1]);
            }
        }
    }
    return dp[sum][n];
}

int main()
{
    int arr[] = {5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << code(arr, n, 100) << endl;
    // cout << ggg(arr, n, 100) << endl;
    return 0;
}
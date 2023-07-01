#include <bits/stdc++.h>
using namespace std;

int matmult(int *arr, int i, int j)
{

    if (i + 1 == j)
    {
        return 0;
    }
    int res = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        res = min(res, matmult(arr, i, k) + matmult(arr, k, j) + arr[i] * arr[j] * arr[k]);
    }
    return res;
}

// dp

int dp[1001][1001] = {-1};
int matmultdp(int *arr, int i, int j)
{
    if (i + 1 == j)
    {
        return dp[i][j] = 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    else
    {
        int res = INT32_MAX;
        for (int k = i + 1; k < j; k++)
        {
            int temp = matmultdp(arr, i, k) + matmultdp(arr, k, j) + arr[i] * arr[k] * arr[k];
            res = min(res, temp);
        }
        return res;
    }
}

// bottom up dp

int matmultup(vector<int> &arr)
{
    int n = arr.size();
    int dp[n][n];
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = 0;
    }
    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = INT32_MAX;
            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j]);
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    cout << matmultup(arr);
    return 0;
}
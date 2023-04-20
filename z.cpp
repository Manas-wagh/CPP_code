#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &arr, int sum)
    {
        int n = arr.size();
        int dp[sum + 1][n + 1];
        for (int i = 0; i < sum + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                dp[i][j] = INT_MAX;
            }
        }
        for (int i = 0; i < n + 1; i++)
        {
            dp[0][i] = 1;
        }
        for (int i = 0; i < sum + 1; i++)
        {
            dp[i][0] = 0;
        }
        dp[0][0] = 1;

        for (int i = 1; i < sum + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                if (arr[j - 1] <= i)
                {
                    dp[i][j] += min(dp[i][j], dp[i - arr[j - 1]][j]);
                }
            }
        }

        return dp[sum][n];
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
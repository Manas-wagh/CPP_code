#include <bits/stdc++.h>
using namespace std;

// normal recursison time comp=O(2^n);
// we have two choices for each element, weather to pick it or not

int SS(int *arr, int n, int sum)
{
    if (n == 0)
    {
        return (sum == 0) ? 1 : 0;
    }
    else
    {
        return SS(arr, n - 1, sum) + SS(arr, n - 1, sum - arr[n - 1]);
    }
}

int SSdp(int *arr, int n, int sum, vector<int> &ans, set<int> &s)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i < sum + 1; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                if (dp[i - 1][j - arr[i - 1]] && s.find(i - 1) == s.end())
                {
                    ans.push_back(arr[i - 1]);
                    s.insert(i - 1);
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int arr[6] = {1, 2, 2};
    vector<int> ans;
    set<int> s;
    cout << SSdp(arr, 3, 5, ans, s) << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
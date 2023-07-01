#include <bits/stdc++.h>
using namespace std;

int dp[7000][7000] = {-1};
bool solve(string A, int i, int j, unordered_set<string> &dict)
{
    if (i > j)
    {
        return false;
    }
    if (dict.find(A.substr(i, j - i + 1)) != dict.end())
    {
        return dp[i][j] = true;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    bool flag = false;
    for (int k = i; k < j; k++)
    {
        flag = flag || (solve(A, i, k, dict) && solve(A, k + 1, j, dict));
    }
    return dp[i][j] = flag;
}

int wordBreak(string A, vector<string> &B)
{
    unordered_set<string> dict;
    for (int i = 0; i < B.size(); i++)
    {
        dict.insert(B[i]);
    }
    return solve(A, 0, A.size() - 1, dict);
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
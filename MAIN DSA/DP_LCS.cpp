#include <bits/stdc++.h>
using namespace std;

// lcs plain recursive

int LCS(string &s1, string &s2, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (s1[m - 1] == s2[n - 1])
    {
        return 1 + LCS(s1, s2, m - 1, n - 1);
    }
    else
    {
        return max(LCS(s1, s2, m, n - 1), LCS(s1, s2, m - 1, n));
    }
}

// lcs memoized

int LCSmemo(string &s1, string &s2, int m, int n)
{
    int dp[m + 1][n + 1];
    memset(dp, -1, sizeof(dp));

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    else
    {
        if (m == 0 || n == 0)
        {
            dp[m][n] = 0;
        }
        else
        {
            if (s1[m - 1] == s2[n - 1])
            {
                dp[m][n] = 1 + LCSmemo(s1, s2, m - 1, n - 1);
            }
            else
            {
                dp[m][n] = max(LCSmemo(s1, s2, m - 1, n), LCSmemo(s1, s2, m, n - 1));
            }
        }
    }
    return dp[m][n];
}

// lcs tabulized

int LCStab(string &s1, string &s2, int m, int n)
{

    int dp[m + 1][n + 1] = {-1};
    for (int i = 0; i < n + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i < m + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{

    string s1 = "manas";
    string s2 = "manasvi";
    cout << LCStab(s1, s2, s1.size(), s2.size());
    return 0;
}
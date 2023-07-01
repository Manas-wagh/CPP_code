#include <bits/stdc++.h>
using namespace std;

int dp[451][451];

int solve(string &A, string &B, int m, int n)
{

    for (int i = 0; i <= m; i++)
        dp[i][0] = i; // subjected to base conditons in recursive Solution

    for (int j = 0; j <= n; j++)
        dp[0][j] = j; // subjected to base conditons in recursive Solution

    for (int i = 1; i <= m; i++)
    {

        for (int j = 1; j <= n; j++)
        {

            if (A[i - 1] == B[j - 1])
            { // if both letters matches

                dp[i][j] = dp[i - 1][j - 1]; /// no operation
            }
            else
            { // if letters dismatches

                dp[i][j] = 1 + min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]); // get min of 3 possibilities(replace, delete, insert)
            }
        }
    }

    return dp[m][n];
}

int minDistance(string A, string B)
{

    int m = A.size(), n = B.size();

    return solve(A, B, m, n);
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
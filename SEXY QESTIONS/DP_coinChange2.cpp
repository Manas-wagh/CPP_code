#include <bits/stdc++.h>
using namespace std;

// You are given a set of coins A. In how many ways can you make sum B assuming you have an infinite amount of each coin in the set.

// -->  SPACE COMP MUST BE O(N);....hence we use prefixing dp

int coinchange2(vector<int> &A, int B)
{
    int mod = 1000007;
    int n = A.size();
    vector<int> dp(B + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= B; j++)
        {
            if (j >= A[i - 1])
            {
                dp[j] += dp[j - A[i - 1]];
                dp[j] %= mod;
            }
        }
    }
    return dp[B];
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
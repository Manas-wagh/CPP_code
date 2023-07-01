#include <bits/stdc++.h>
using namespace std;

// dp

// while filling the minimum number of jumps required to reach an index, you have to ensure the inner loop doesn’t run if the max index reached by a jump is already filled. dp here stores the min jumps required to reach a particular index, initialized to INT_MAX.

int jump(vector<int> &A)
{
    int n = A.size();
    vector<int> dp(n, 1000000);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] + 1 < dp[min(n - 1, i + A[i])])
        {
            for (int j = 1; j <= A[i]; j++)
            {
                if (i + j < n)
                {
                    dp[i + j] = min(dp[i] + 1, dp[i + j]);
                }
            }
        }
    }
    if (dp[n - 1] == 1000000)
    {
        return -1;
    }
    else
    {
        return dp[n - 1];
    }
}

// greedy

int jump(vector<int> &A)
{

    int farthest = 0;

    int current = 0;

    int jumps = 0;

    for (int i = 0; i < A.size() - 1; i++)

    {

        farthest = max(farthest, A[i] + i);

        if (current == i)

        {

            current = farthest;

            jumps++;
        }
    }

    if (current >= A.size() - 1)
    {
        return jumps;
    }

    else
    {
        return -1;
    }
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
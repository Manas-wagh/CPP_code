
// Given three prime numbers A, B and C and an integer D.

// You need to find the first(smallest) D integers which only have A, B, C or a combination of them as their prime factors.

#include <bits/stdc++.h>
using namespace std;

// MIN HEAP
vector<int> solve(int A, int B, int C, int D)
{
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(A);
    if (B != A)
        q.push(B);
    if (C != A && C != B)
        q.push(C);
    unordered_map<int, int> m;
    m[A]++;
    m[B]++;
    m[C]++;
    vector<int> ans;
    while (ans.size() < D)
    {
        int val = q.top();
        q.pop();
        ans.push_back(val);
        if (m.find(val * A) == m.end())
        {
            q.push(val * A);
            m[val * A]++;
        }
        if (m.find(val * B) == m.end())
        {
            q.push(val * B);
            m[val * B]++;
        }
        if (m.find(val * C) == m.end())
        {
            q.push(val * C);
            m[val * C]++;
        }
    }
    return ans;
}

// DP
vector<int> solve(int A, int B, int C, int D)
{

    vector<int> dp(D + 1);

    dp[0] = 1;

    int p2 = 0, p3 = 0, p5 = 0;

    for (int i = 1; i <= D; i++)
    {

        int f1 = A * dp[p2];

        int f2 = B * dp[p3];

        int f3 = C * dp[p5];

        int mini = min(f1, min(f2, f3));

        dp[i] = mini;

        if (f1 == mini)
        {

            p2++;
        }

        if (f2 == mini)
        {

            p3++;
        }

        if (f3 == mini)
        {

            p5++;
        }
    }

    dp.erase(dp.begin());

    return dp;
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
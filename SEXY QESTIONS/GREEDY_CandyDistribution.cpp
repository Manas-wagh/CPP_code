#include <bits/stdc++.h>
using namespace std;

// type of peak valley problem

int candy(vector<int> &A)
{
    int lr[A.size()];
    int rl[A.size()];
    int ans = 0;
    lr[0] = 1;
    rl[A.size() - 1] = 1;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] > A[i - 1])
        {
            lr[i] = lr[i - 1] + 1;
        }
        else if (A[i] == A[i - 1])
        {
            lr[i] = 1;
        }
        else
        {
            lr[i] = 1;
        }
    }
    for (int i = A.size() - 2; i > -1; i--)
    {
        if (A[i] > A[i + 1])
        {
            rl[i] = rl[i + 1] + 1;
        }
        else if (A[i] == A[i + 1])
        {
            rl[i] = 1;
        }
        else
        {
            rl[i] = 1;
        }
    }
    for (int i = 0; i < A.size(); i++)
    {
        ans = ans + max(lr[i], rl[i]);
    }
    return ans;
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
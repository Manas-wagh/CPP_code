#include <bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &A)
{

    int res;
    int cnt = A[0];
    res = A[0];

    for (int i = 1; i < A.size(); i++)
    {
        if (cnt + A[i] > 0)
        {
            cnt += A[i];
            res = max(res, cnt);
        }
        else
        {
            cnt = 0;
            res = max(res, A[i]);
        }
    }

    return res;
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
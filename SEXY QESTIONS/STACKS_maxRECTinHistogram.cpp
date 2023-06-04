#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &A)
{
    stack<int> s1;
    vector<int> nsl(A.size());
    int i = 0, n = A.size();

    while (i < n)
    {
        if (s1.empty())
            nsl[i] = -1;
        else if (!s1.empty() && A[s1.top()] < A[i])
            nsl[i] = s1.top();
        else
        {
            while (!s1.empty() && A[s1.top()] >= A[i])
            {
                s1.pop();
            }
            nsl[i] = (s1.empty()) ? -1 : s1.top();
        }
        s1.push(i);
        i++;
    }

    vector<int> nsr(n);
    stack<int> s2;
    i = n - 1;
    while (i >= 0)
    {
        if (s2.empty())
            nsr[i] = n;
        else if (A[s2.top()] >= A[i])
        {
            while (!s2.empty() && A[s2.top()] >= A[i])
            {
                s2.pop();
            }
            nsr[i] = (s2.empty()) ? n : s2.top();
        }
        else
            nsr[i] = s2.top();
        s2.push(i);
        i--;
    }
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (nsr[i] - nsl[i] - 1) * A[i]);
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
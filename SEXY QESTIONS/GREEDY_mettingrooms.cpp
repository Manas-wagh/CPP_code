#include <bits/stdc++.h>
using namespace std;

static bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] < b[0] || a[0] == b[0] && a[1] < b[1])
        return true;
    return false;
}
int solve(vector<vector<int>> &A)
{

    sort(A.begin(), A.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> pq;

    int cnt = A.size();

    for (int i = 0; i < A.size(); i++)
    {

        if (!pq.empty() && pq.top() <= A[i][0])
        {
            cnt--;
            pq.pop();
        }

        pq.push(A[i][1]);
    }

    return cnt;
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
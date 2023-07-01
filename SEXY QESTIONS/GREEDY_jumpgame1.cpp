#include <bits/stdc++.h>
using namespace std;

int canJump(vector<int> &A)
{
    int next = A.size() - 1;
    for (int i = A.size() - 2; i >= 0; --i)
    {
        if (A[i] >= (next - i))
        {
            next = i;
        }
    }
    return (next == 0) ? 1 : 0;
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
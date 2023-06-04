#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &A)
{
    assert(A.size() >= 1 && A.size() <= 1e6);
    int count = 0, n = A.size();
    for (int i = 0; i < n; i++)
    {
        assert(A[i] >= 0 && A[i] <= 2e9);
        if (i < n - 1 && A[i] == A[i + 1])
            continue;
        else
        {
            A[count] = A[i];
            count++;
        }
    }
    return count;
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
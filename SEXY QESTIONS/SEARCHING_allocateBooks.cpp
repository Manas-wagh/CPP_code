#include <bits/stdc++.h>
using namespace std;

bool chechk(vector<int> &A, int k, int req)
{
    int student = 1;
    int page = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] + page > k)
        {
            student++;
            page = A[i];
        }
        else
        {
            page += A[i];
        }
    }
    return (student <= req);
}

int books(vector<int> &A, int B)
{
    if (A.size() < B)
        return -1;
    assert(A.size() <= 100000);
    long long low = (*max_element(A.begin(), A.end()));
    long long high = accumulate(A.begin(), A.end(), 0);
    assert(low <= 100000);
    long long mid;
    long long res = INT32_MAX;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (chechk(A, mid, B))
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return res;
}

int main()
{

    int t;
    cin >> t;
    vector<int> arr{10, 20, 10, 30};
    while (t--)
    {
        cout << books(arr, 2);
    }
    return 0;
}
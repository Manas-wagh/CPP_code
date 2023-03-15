#include <bits/stdc++.h>
using namespace std;

// LIS normal

int LIS(int *arr, int n)
{
    int lis[n];
    lis[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        res = max(res, lis[i]);
    }
    return res;
}

// LIS optimised

int ceilind(int *arr, int l, int r, int x)
{
    while (r > l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return r;
}

int LISopt(int *arr, int n)
{
    int tail[n];
    tail[0] = arr[0];
    int len = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > tail[len - 1])
        {
            tail[len] = arr[i];
            len++;
        }
        else
        {
            int c = ceilind(tail, 0, len - 1, arr[i]);
            tail[c] = arr[i];
        }
    }
    return len;
}

int main()
{

    int arr[6] = {2, 3, 6, 4, 10, 1};
    cout << LISopt(arr, 6);
    return 0;
}
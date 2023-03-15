#include <bits/stdc++.h>
using namespace std;

int LIS(int *arr, int n)
{
    int sum[n];
    sum[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        sum[i] = arr[i];

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                sum[i] = max(sum[i], sum[j] + arr[i]);
            }
        }
    }
    int res = sum[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, sum[i]);
    }
    return res;
}

int main()
{
    int arr[6] = {3, 20, 4, 6, 7, 30};
    cout << LIS(arr, 6);

    return 0;
}
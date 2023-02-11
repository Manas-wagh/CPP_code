#include <bits/stdc++.h>
using namespace std;

int bucketsort(int *arr, int n, int k)
{
    int maxval = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        maxval = max(maxval, arr[i]);
    }
    maxval++;

    vector<int> bucket[k]; // array of vectors;

    for (int i = 0; i < n; i++)
    {
        int ind = (k * arr[i]) / maxval;
        bucket[ind].push_back(arr[i]);
    }
    for (int i = 0; i < k; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[index++] = bucket[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i < n; i++)
    {

        if (n == 0 || n == 1)
        {
            return 0;
        }
        res = max(res, arr[i] - arr[i - 1]);
    }
    return res;
}

int main()
{

    int arr[] = {1, 8, 3, 9, 10, 10, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << bucketsort(arr, n, 100);
    return 0;
}
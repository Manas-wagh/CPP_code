#include <bits/stdc++.h>
using namespace std;

int matmult(int *arr, int i, int j)
{

    if (i + 1 == j)
    {
        return 0;
    }
    int res = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        res = min(res, matmult(arr, i, k) + matmult(arr, k, j) + arr[i] * arr[j] * arr[k]);
    }
    return res;
}

int main()
{
    return 0;
}
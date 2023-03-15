#include <bits/stdc++.h>
using namespace std;

int code(int *arr, int n, int sum)
{

    if (n == 0 && sum == 0)
    {
        return 0;
    }
    if (n == 0 && sum != 0)
    {
        return 1000;
    }
    if (n != 0 && sum == 0)
    {
        return 0;
    }
    else
    {
        if (arr[n - 1] > sum)
        {
            return code(arr, n - 1, sum);
        }
        else
        {
            return 1 + min(code(arr, n - 1, sum), code(arr, n, sum - arr[n - 1]));
        }
    }
    return 0;
}

int main()
{
    int arr[] = {5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << code(arr, n, 100) << endl;
    // cout << ggg(arr, n, 100) << endl;
    return 0;
}
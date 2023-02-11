#include <bits/stdc++.h>
using namespace std;

// iterative code
int BinarySearch(int arr[], int n, int x)
{
    int h = n - 1, l = 0;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (x == arr[mid])
        {
            return 1;
        }
        else if (x < arr[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

// recursive code;

int BinarySearchRec(int arr[], int l, int h, int x)
{
    if (l > h)
    {
        return -1;
    }

    int mid = (l + h) / 2;

    if (x == arr[mid])
    {
        return 1;
    }
    else if (x < arr[mid])
    {
        BinarySearchRec(arr, l, mid - 1, x);
    }
    else
    {
        BinarySearchRec(arr, mid + 1, h, x);
    }
}

// square root using binary search

int Squrt(int x)
{
    int l = 1, h = x, ans = -1;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (x == mid * mid)
        {
            return mid;
        }
        else if (x < mid * mid)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

int main()
{
    // int n;
    // cin >> n;
    // int arr[n];

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // int x;
    // cin >> x;

    // cout << BinarySearch(arr, n, x);

    cout << Squrt(10000);

    return 0;
}
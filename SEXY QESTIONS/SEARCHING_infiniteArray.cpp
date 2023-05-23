#include <bits/stdc++.h>
using namespace std;

int infArr(int arr[], int n, int k)
{
    if (arr[0] == k)
    {
        return 0;
    }
    int i = 0;
    int ind = 1;
    while (arr[i] < k)
    {
        ind = ind * 2;
        i++;
    }
    if (arr[i] == k)
    {
        return i;
    }
    int h = i - 1, l = 0;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (k == arr[mid])
        {
            return mid;
        }
        else if (k < arr[mid])
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

int main()
{

    int t;
    cin >> t;
    int arr[4] = {10,
                  20,
                  1,
                  40};
    while (t--)
    {
        cout << infArr(arr, 4, 40);
    }
    return 0;
}
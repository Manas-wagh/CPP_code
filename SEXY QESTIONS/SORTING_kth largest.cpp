#include <bits/stdc++.h>
using namespace std;

int lomutopartition(int *a, int l, int h)
{
    int pivot = a[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[h]);
    return (i + 1);
}

int kthlargest(int *arr, int k, int l, int h, int ind)
{

    if (lomutopartition(arr, l, h) == ind)
    {
        return arr[lomutopartition(arr, l, h)];
    }
    else if (lomutopartition(arr, l, h) > ind)
    {
        kthlargest(arr, k, l, lomutopartition(arr, l, h) - 1, ind);
    }
    else
    {
        kthlargest(arr, k, lomutopartition(arr, l, h) + 1, h, ind);
    }
}

int main()
{

    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << kthlargest(arr, k, 0, n - 1, n - k);
    return 0;
}
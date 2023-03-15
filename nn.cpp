#include <bits/stdc++.h>
using namespace std;

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

int LIS(set<pair<int, int>> p, int n)
{
    int arr[p.size()];
    int arr2[p.size()];
    int call;
    int c = 0;
    call = 0;
    if (p.size() == 1)
    {
        return 1;
    }
    for (auto i : p)
    {
        arr[c] = i.second;
        arr2[c] = i.first;
        c++;
    }
    // for (int i = 0; i < p.size(); i++)
    // {
    //     cout << arr[i] << endl;
    // }
    int tail[p.size()];
    tail[0] = arr[0];
    int len = 1;

    for (int i = 1; i < p.size(); i++)
    {
        if (arr[i] > tail[len - 1] && (arr2[i] != arr2[call]))
        {
            tail[len] = arr[i];
            len++;
            call = i;
        }
        else if (arr2[i] == arr2[call])
        {
        }
        else
        {
            int c = ceilind(tail, 0, len - 1, arr[i]);
            if (c == len - 1)
            {
            }
            else
            {
                tail[c] = arr[i];
            }
        }
    }
    return len;
}

int main()
{

    int m, n;
    cin >> n;
    set<pair<int, int>> arr;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.insert(make_pair(x, y));
    }

    for (auto i : arr)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << LIS(arr, n) << endl;

    return 0;
}
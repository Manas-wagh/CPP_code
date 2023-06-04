#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &arr)
{
    int l = 0, mid = 0, h = arr.size() - 1;
    while (mid <= h)
    {
        if (arr[mid] == 0 && mid == l)
        {
            mid++;
            l++;
        }
        else if (arr[mid] == 0)
        {
            swap(arr[mid], arr[l]);
            l++;
        }
        else if (arr[mid] == 1)
        {
            swap(arr[mid], arr[mid]);
            mid++;
        }
        else
        {
            swap(arr[mid], arr[h]);
            h--;
        }
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
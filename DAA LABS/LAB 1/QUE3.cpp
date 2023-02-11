#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int res = 0;
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            cnt++;
        }
        else
        {
            if (cnt == 0)
            {
                res = i;
            }
            else
            {
                cnt--;
            }
        }
    }
    cout << arr[res] << endl;

    return 0;
}
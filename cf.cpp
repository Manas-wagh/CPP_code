#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#include <chrono>

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int res = 0;
        int arr[n];

        int maxi = 1;
        while (maxi <= 1e9)
        {
            maxi *= 2;
        }
        maxi--;
        int mint = maxi;
        int xori = maxi;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            mint = mint & arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            xori = xori & arr[i];
            if (xori == 0)
            {
                res++;
                xori = maxi;
            }
        }
        // trial uotput
        res += mint > 0;
        cout << res << endl;
    }

    return 0;
}
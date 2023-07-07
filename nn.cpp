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
    int test;
    cin >> test;
    while (test--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n + 2);
        ll egt = 0;
        ll cnt;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; i++)
        {
            egt = max(egt, arr[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            cnt = arr[i];
            for (int j = i + 1; j <= min(n, (ll)i + 256); j++)
            {
                cnt ^= arr[j];
                egt = max(egt, cnt);
            }
        }
        cout << egt << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int rec = 0;
        int sum = 1;
        for (int i = 1; i < n; i++)
        {
            if (str[i] != str[i - 1])
            {
                rec = max(rec, sum);
                sum = 1;
            }
            else
            {
                sum++;
            }
        }
        rec = max(sum, rec);
        int ans = rec + 1;
        cout << ans << endl;
    }
    return 0;
}
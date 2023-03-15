#include <bits/stdc++.h>
using namespace std;

int soln()
{
    int n;
    cin >> n;

    int arr[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    int dp[n + 1][3];
    for (int i = 0; i < 3; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + arr[i - 1][j];
        }
    }
    cout << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return min(dp[n][0], min(dp[n][1], dp[n][2]));
}

int main()
{

    cout << soln();

    return 0;
}
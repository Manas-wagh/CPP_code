#include <bits/stdc++.h>
using namespace std;

int house_coloring(vector<vector<int>> arr){
    int N = 3;
    int dp[3][N] = {0};
    int r[] = {2, 1, 3} ;
    int g[] = {3, 2, 1} ;
    int b[] = {1, 3, 2};

    dp[0][0] = r[0];
    dp[1][0] = g[0];
    dp[2][0] = b[0];

    for (int i = 1; i < N; i++)
    {
        
           dp[0][i]=r[i]+min(dp[1][i-1],dp[2][i-1]);
           dp[1][i]=g[i]+min(dp[0][i-1],dp[2][i-1]);
           dp[2][i]=r[i]+min(dp[1][i-1],dp[0][i-1]);





        
    }

    int mini = dp[0][N - 1];
    for (int k = 0; k < 3; k++)
    {

        mini = min(dp[k][N-1], mini);
    }

    return mini;
}



int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
    }

    cout << house_coloring(arr);

    return 0;
}
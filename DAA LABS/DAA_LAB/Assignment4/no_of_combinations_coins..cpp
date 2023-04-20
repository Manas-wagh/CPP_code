#include <bits/stdc++.h>
using namespace std;


int coins_combination_dp(vector<int>&coins,int n,int sum){

  //taking dp[n+1][sum+1] would have created problem as 
  //then you would traverse for n considering the coins
  //in such case the combinations would repeat
  int dp[sum+1][n+1];
  for(int i=1;i<sum+1;i++){
    dp[i][0]=0;
  }
  for(int i=0;i<n+1;i++){
    dp[0][i]=1;
  }
  int res=0;

  for(int i=1;i<sum+1;i++){
    for(int j=1;j<n+1;j++){
      if(i==0){return 1;}
      if(j==0){return 0;}{

        dp[i][j]=dp[i][j-1];
        if(coins[j-1]<=i){
          dp[i][j]+=dp[i-coins[j-1]][j];
        }
      }
    }
  }
  return dp[sum][n];
}

int coins_combination(vector<int> &coins, int sum, int n)
{
    int dp[sum + 1];
    // sort(coins.begin(), coins.end());
    for (int i = 0; i < sum + 1; i++)
    {
        dp[i] = 0;
    }

    dp[0] = 1;

    for (int j = 0; j<n; j++)
    {
        for (int i = 1; i < sum + 1; i++)
        {
            // int possib=0;
            // if(dp[i-coins[j]]!=INT_MAX&&i-coins[j]>=0){
            //     possib+=dp[i-coins[j]];
            // }
            
            // if(possib!=0){
            //     if(dp[i]==INT_MAX){
            //         dp[i]=0;
            //     }
            //     dp[i]+=possib;
            // }
            if(i-coins[j]>=0){
                dp[i]+=dp[i-coins[j]];
            }
            
        }
    }

    
    return dp[sum];
}
int main()
{
    int n;
    int sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << coins_combination(coins, sum, n)<<endl;
    cout<<coins_combination_dp(coins, n,sum);
    return 0;
}
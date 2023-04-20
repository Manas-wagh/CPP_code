#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dp[n][n];
    int a[n][n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            dp[i][j]=INT_MAX;
        }
    }


    dp[0][0]=a[0][0];
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> x;
    pair<int,int> y;
    y.first=0;
    y.second=0;
    set<pair<int,int>> t;
    x.push({a[0][0],y});
    while(!x.empty()){
        pair<int,pair<int,int>> z=x.top();
        x.pop();
        if(t.find(z.second)==t.end()){

        
        int i=z.second.first;
        int j=z.second.second;
        t.insert({i,j});
        if(i+1<n){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i+1][j]);
            x.push({dp[i+1][j],{i+1,j}});
        }
        if(i-1>=0){
            dp[i-1][j]=min(dp[i-1][j],dp[i][j]+a[i-1][j]);
            x.push({dp[i-1][j],{i-1,j}});
        }
        if(j-1>=0){
            dp[i][j-1]=min(dp[i][j-1],dp[i][j]+a[i][j-1]);
            x.push({dp[i][j-1],{i,j-1}});
        }
        if(j+1<n){
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+a[i][j+1]);
            x.push({dp[i][j+1],{i,j+1}});
        }
        }
    }



    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
   }
return 0;
}
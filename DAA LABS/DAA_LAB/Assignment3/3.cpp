#include<bits/stdc++.h>
using namespace std;
// int coinChange(vector<int>& coins, int amount) {
//         sort(coins.begin(),coins.end());
//         int val=amount;
//         int count =0;
//         int s=coins.size();
//         if(amount==0){
//             return 0;

//         }
//         for(int i=0;i<s;i++){
//             if(val==0){
//                 break;
//             }
//             count=count+(val/coins[s-i-1]);
//             val=val%coins[s-i-1];

//         }
//         if(val==0){
//         return count;
//         }
//         return -1;
        
//     }

    int final_coin_count(vector<int>& coins, int amount){
        int arr[amount+1];
        arr[0]=0;
        for(int i=1;i<amount+1;i++){
            arr[i]=INT16_MAX;
        }
        for(int i=0;i<amount+1;i++){
            for(int j=0;j<coins.size();j++){
                
                if(i-coins[j]>=0 && arr[i-coins[j]]!=INT16_MAX){
                    arr[i]=min(arr[i],(arr[i-coins[j]])+1);
                }
            }
            
        }
        return arr[amount];

    }
int main(){
    int n;
    cin>>n;
    int amount;
    cin>>amount;
    vector<int> coins(n) ;  
    for(int i=0;i<n;i++){
            
        cin>>coins[i];
        }

    cout<<final_coin_count(coins,amount);
  return 0;
}
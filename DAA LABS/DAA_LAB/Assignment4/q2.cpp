#include<bits/stdc++.h>
using namespace std;

int stock_b_s(vector<int>&price){
    int sum=0;
    for(int i=0;i<price.size()-1;i++){
        if(price[i+1]>price[i]){
            sum+=price[i+1]-price[i];
        }
    }
    return sum;
}
int main(){
   int n; 
   cin>>n;
   vector<int>price(n);
   for(int i=0;i<n;i++){
         cin>>price[i];
    } 

    cout<<stock_b_s(price);      
  return 0;
}
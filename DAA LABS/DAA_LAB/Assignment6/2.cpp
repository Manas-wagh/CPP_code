#include<bits/stdc++.h>
using namespace std;

int addsubkdiffernce(vector<int>&arr,int k){
     sort(arr.begin(),arr.end());
     int ans=arr[arr.size()-1]-arr[0];
     
     int mi1=INT16_MAX;
     
     int mi=0;
     int mx=0;
     for(int i=0;i<arr.size()-1;i++){
         mx=max(arr[i]+k,arr[arr.size()-1]-k);
         mi=min(arr[i+1]-k,arr[0]+k);
         ans=min(ans,mx-mi);

     }

     return ans;

}
int main(){
         vector<int>arr;
         int n,k;
         cin>>n,k;
         for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
         }
  return 0;
}
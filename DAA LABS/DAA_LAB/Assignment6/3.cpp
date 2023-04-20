#include<bits/stdc++.h>
using namespace std;

int wiggleseq(vector<int>&nums){
    vector<int>arr;
    for(int i=0;i<nums.size()-1;i++){
       arr.push_back(nums[i+1]-nums[i]);
    }     

    int prev=arr[0];
    
    int ans=1;
    for(int i=1;i<arr.size();i++){
        if(arr[i]*prev<0){
            ans++;
            prev=arr[i];
        }
    }
    return ans+1;


    
}
int main(){
   int n; 
   cin>>n;
   vector<int>nums;

   for(int i=0;i<n;i++){
       int x;
        cin>>x;
        nums.push_back(x); 
    }    

    cout<<wiggleseq(nums);   
  return 0;
}
#include<bits/stdc++.h>
using namespace std;

int mostwater(vector<int>&height){
    int n=height.size();
    
    int b=0;
    int e=n-1;
    int maxw=0;
    while(b<e){

        
        int currw=0;
        if(height[b]>height[e]){
            currw=(e-b)*height[e];
            e--;
        }
        else{
            currw=(e-b)*height[b];
            b++;          
        }
        maxw=max(maxw,currw);
        
    }

    return maxw;
}
int main(){

   int n; 
   cin>>n;
   vector<int>water;
   for(int i=0;i<n;i++){
         int x;
         cin>>x;
         water.push_back(x);
    }    

    cout<<mostwater(water);   
  return 0;
}
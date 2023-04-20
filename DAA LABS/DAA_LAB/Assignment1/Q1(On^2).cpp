#include<bits/stdc++.h>
using namespace std;
int main(){
    int inversion=0;
    int m;
    cin>>m;
    int arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
        if(arr[i]>arr[j]){
            inversion++;
        }
    }
    }
    cout<<inversion;


  return 0;
}
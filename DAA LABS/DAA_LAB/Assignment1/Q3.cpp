#include<bits/stdc++.h>
using namespace std;


int main(){
    
    int m;
    cin>>m;
    int arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    int index=0;
    int repitition=0;
    for(int i=1;i<m;i++){
        if(arr[i]==arr[i-1]){
            repitition++;
        }
        else{
            if(repitition==0){
                index++;

            }
            else{
                repitition--;
            }
        }
    }
    cout<<arr[index];



  return 0;
}
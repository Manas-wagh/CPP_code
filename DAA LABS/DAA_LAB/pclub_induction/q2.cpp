#include<bits/stdc++.h>
using namespace std;
int main(){
   int n; 
   cin>>n;
   int m;
   cin>>m;
    set<string>s;
   for(int i=0;i<m;i++){
        string x;
        cin>>x;
        s.insert(x);

    }  
    for(auto i:s){
        cout<<i<<endl;
    }     
  return 0;
}
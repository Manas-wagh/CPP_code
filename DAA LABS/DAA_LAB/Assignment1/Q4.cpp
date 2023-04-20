#include<bits/stdc++.h>
using namespace std;
int main(){
   priority_queue<int>q;
   int m;
   int k;
   cin>>m;
   cin>>k;
   for(int i=0;i<m;i++){
    int x;
    cin>>x;
    q.push(x);
   }    
   while(k-1>0){
    q.pop();
    k--;
   }
   cout<<q.top();
  return 0;
}
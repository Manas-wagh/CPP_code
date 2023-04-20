#include<bits/stdc++.h>
using namespace std;

bool mycomp(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
    int x=a.second.second;
    int y=b.second.second;
    if(x>=y){
        return a>=b;
    }
    else{
        return a<b;
    }
}


pair<int,int> maxprofit(vector<pair<int,pair<int,int>>>&jobs){
    sort(jobs.begin(),jobs.end(),mycomp);
    int maxdeadline=0;
    for(int i=0;i<jobs.size();i++){
        maxdeadline=max(maxdeadline,jobs[i].second.first);

    }
    int hsh[maxdeadline+1]={0};
    for(int i=0;i<jobs.size();i++){
        int x=jobs[i].second.first;
        for(int j=x;j>=1;j--){
            if(hsh[j]==0){
                hsh[j]=jobs[i].second.second;
                break;
            }
        }

    }
    int profit=0;
    int jobcount=0;
    for(int i=0;i<=maxdeadline;i++){
        profit+=hsh[i];
        if(hsh[i]!=0){
            jobcount++;
        }

        

    }

    return {jobcount,profit};
    





}
int main(){
   int n; 
   cin>>n;
   vector<pair<int,pair<int,int>>>jobs;

   for(int i=0;i<n;i++){
    int x,y,z;
    cin>>x>>y>>z;
    
    jobs.push_back({x,{y,z}});
         
    } 
    pair<int,int>ans;
    ans=maxprofit(jobs);

    cout<<ans.first<<" "<<ans.second; 
    


    // for(int i=0;i<n;i++){
    // cout<<jobs[i].first<<" "<<jobs[i].second.first<<" "<<jobs[i].second.second<<endl;
         
    // } 

  return 0;
}
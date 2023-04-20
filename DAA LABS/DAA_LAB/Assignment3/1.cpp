#include<bits/stdc++.h>
using namespace std;
void countSort(vector<pair<int,int>>&arr, int n, int exp){
	int output[n]; 
	int i, count[10] = { 0 };

	
	for (i = 0; i < n; i++)
		count[(arr[i].first / exp) % 10]++;

	
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i].first / exp) % 10] - 1] = arr[i].first;
		count[(arr[i].first / exp) % 10]--;
	}

	
	for (i = 0; i < n; i++)
		arr[i].first = output[i];
}

vector<int> trimsort(vector<pair<int,int>> &nums1,vector<pair<int,int>> &query){
    int n = nums1.size();
    int m = query.size();
    int kthsmallest;
    int k;
    vector<pair<int,int>> ari;
    ari=nums1;
  
    vector<int>ans;
   
    for(int i=0;i<m;i++){
        
        
        k = query[i].second;
        kthsmallest = query[i].first;
        
        int t = pow(10,(k-1));
        countSort(nums1,n,t);
        // for(int j=0;j<n;j++){
        //     cout<<nums1[j].first<<" ";
        // }
        int k;
        // cout<<nums1[kthsmallest-1].first<<" ";
        int num = nums1[kthsmallest-1].first;
        for(int j=0;j<n;j++){
            if(ari[j].first==num){
                k=j;
                break;
            }
        }
        
        ans.push_back(k);
}
return ans;

    
}







int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<string> nums(n);
    vector<pair<int,int>> nums1(n);
    vector<pair<int,int>> query(m);
    for(int i=0;i<n;i++){
        cin>>nums1[i].first;
        // nums1[i].first=stoi(nums[i]);
        nums1[i].second=i;
    }
    
    for(int i=0;i<m;i++){
        cin>>query[i].first>>query[i].second;
    }
    vector<int>ans;
    ans=trimsort(nums1,query);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


  return 0;
}




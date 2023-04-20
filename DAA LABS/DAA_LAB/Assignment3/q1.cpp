#include <iostream>
#include<bits/stdc++.h>
using namespace std;



// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(vector<int>&arr, int n, int exp){
	int output[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}


vector<int> run(vector<int>&arr,vector<pair<int,int>>query){
    int n = arr.size();
    int m = query.size();
    int kthsmallest;
    int k;
  
    vector<int>ans;
   
    for(int i=0;i<m;i++){
        vector<int>ari;
        ari = arr;
        k = query[i].second;
        kthsmallest = query[i].first;
        int t = 10^(k-1);
        countSort(ari,n,t);
        int num = ari[kthsmallest-1];
        int poly;
        for(int i=0;i<n;i++){
            if(arr[i]==num){
                poly = i;
            }
        }
        ans.push_back(poly);
}
return ans;

}
int main(){
vector<int> arr = {102,473,251,814};
vector<pair<int,int>> queries = {{1,1},{2,3},{4,2},{1,2}};
vector<int> ans = run(arr,queries);
int z = ans.size();
for(int i=0;i<z;i++){
    cout << ans[i] << " ";
}




  return 0;
}
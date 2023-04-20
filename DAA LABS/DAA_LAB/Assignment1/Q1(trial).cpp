#include<bits/stdc++.h>
using namespace std;
    int cont=0;
    void merge(vector<int>& arr, int p, int r, int q)
    {
        vector<int> temp;
        int i=p, j=r+1;
        while(i<=r&&j<=q)
        {
            if(arr[i]>arr[j])
            {
                temp.push_back(arr[j]);
                cont+=(r+1)-i;
                j++;
            }
            else
            {
                temp.push_back(arr[i]);
                i++;
            }
        } 
        while(i<=r)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=q)
        {
            temp.push_back(arr[j]);
            j++;
        }
        for (int k = p; k <= q; k++)
        {
            arr[k]=temp[k-p];
        }
        
    }
    void merge_sort(vector<int>& arr, int p, int q)
    {
        if(p>=q)
        return;
        int mid=(p+q)/2;
        merge_sort(arr, p, mid);
        merge_sort(arr, mid+1, q);
        merge(arr, p, mid, q);
    }

int main()
{
    vector<int> a;
    int n; cin>>n;
    for(int i=0; i<n; i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    merge_sort(a, 0, n-1);
    cout<<cont;
    
  return 0;
}
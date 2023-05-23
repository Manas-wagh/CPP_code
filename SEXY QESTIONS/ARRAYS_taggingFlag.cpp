#include <bits/stdc++.h>
using namespace std;

vector<int> Flags(vector<int> arr)
{
    vector<int> ans;
    int flag = arr[0];
    ans.push_back(arr[0]);
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= flag)
        {
            flag = arr[i];
            ans.push_back(flag);
        }
        else
        {
        }
    }
    return ans;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        vector<int> arr = {10, 20, 3, 4, 40};
        vector<int> ans = Flags(arr);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}
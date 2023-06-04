#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &arr)
{
    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty() == true)
        {
            ans.push_back(-1);
        }
        else
        {
            while (s.empty() == false && s.top() >= arr[i])
            {
                s.pop();
            }
            if (s.empty() == true)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    return ans;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
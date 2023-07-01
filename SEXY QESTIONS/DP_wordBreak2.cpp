#include <bits/stdc++.h>
using namespace std;
void solve(string A, vector<string> &B, string an, vector<string> &ans, int index)
{
    if (index == A.size())
    {
        ans.push_back(an.substr(0, an.size() - 1));
        return;
    }

    string str = "";
    for (int i = index; i < A.size(); i++)
    {
        str += A[i];
        if (find(B.begin(), B.end(), str) != B.end())
        {
            solve(A, B, an + str + " ", ans, i + 1);
        }
    }
}
vector<string> wordBreak(string A, vector<string> &B)
{
    vector<string> ans;
    string an = "";
    solve(A, B, an, ans, 0);
    sort(ans.begin(), ans.end());
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
#include <bits/stdc++.h>
using namespace std;

bool issafe(int op, int clo, int A)
{
    if (clo > op)
    {
        return false;
    }
    if (op > A)
    {
        return false;
    }
    return true;
}

void solve(vector<string> &ans, string &temp, int A, int op, int clo)
{
    if (temp.size() == 2 * A)
    {
        ans.push_back(temp);
        return;
    }
    else
    {
        if (issafe(op + 1, clo, A))
        {
            temp.push_back('(');
            solve(ans, temp, A, op + 1, clo);
            temp.pop_back();
        }
        if (issafe(op, clo + 1, A))
        {
            temp.push_back(')');
            solve(ans, temp, A, op, clo + 1);
            temp.pop_back();
        }
        return;
    }
}

vector<string> generateParenthesis(int A)
{
    vector<string> ans;
    string s = "";
    solve(ans, s, A, 0, 0);
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
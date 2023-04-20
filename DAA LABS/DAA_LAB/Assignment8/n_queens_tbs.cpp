#include <bits/stdc++.h>
using namespace std;
    bool is(int col, int row, vector<char> ans, vector<vector<char>> &a, int n)
    {
        bool leftup = true;
        bool left = true;
        bool leftdown = true;
        int xx = col;
        int yy = row;

        if (xx == 0)
        {
            return true;
        }
        else
        {
            while (xx != 0)
            {
                xx--;
                if (a[yy][xx] == 'Q')
                {

                    left = false;
                }
            }
            xx = col;
            yy = row;
            while (xx != 0 && yy != 0)
            {
                xx--;
                yy--;

                if (a[yy][xx] == 'Q')
                {
                    // cout<<"q at leftup"<<endl;
                    leftup = false;
                }
            }
            xx = col;
            yy = row;
            while (xx != 0 && yy != n - 1)
            {
                xx--;
                yy++;
                if (a[yy][xx] == 'Q')
                {
                    leftdown = false;
                }
            }
        }
        // cout<<left&&leftup&&leftdown;
        // cout<<endl;
        return (left && leftup && leftdown);
    }
    void s(int col, int n, vector<char> ans, vector<vector<char>> &a, vector<vector<vector<char>>> &aa)
    {
        if (col == n)
        {
            aa.push_back(a);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (is(col, i, ans, a, n) == true)
            {
                // cout<<"vwv"<<endl;
                a[i][col] = 'Q';
                s(col + 1, n, ans, a, aa);
                a[i][col] = '.';
            }
        }
    }
    void d(vector<vector<vector<char>>> aa, vector<vector<string>> &aaa)
    {
        for (auto i : aa)
        {
            vector<string> q;
            for (auto j : i)
            {
                string x = "";
                for (auto k : j)
                {
                    x = x + k;
                }
                q.push_back(x);
            }
            aaa.push_back(q);
        }
    }

int main()
{
        int n=4;
        vector<char> ans;
        vector<vector<char>> a;
        vector<vector<vector<char>>> aa;
        vector<vector<string>> aaa;
        for (int i = 0; i < n; i++)
        {
            ans.push_back('.');
        }

        for (int i = 0; i < n; i++)
        {
            a.push_back(ans);
        }
        s(0, n, ans, a, aa);
        d(aa, aaa);
        for (auto i : aaa)
        {
            for (auto j : i)
            {

                cout << j << " ";

                cout << endl;
            }
            cout << endl;
            cout << endl;
        }
        return 0;

}       

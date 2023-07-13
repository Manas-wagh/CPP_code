#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool flag = false;
        if (n % 3 == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            for (char ele = 'a'; ele <= 'z'; ele++)
            {
                int fi = n + 1, li = -1;
                for (int i = 0; i < n; i++)
                {
                    if (s[i] == ele && i % 3 == 0)
                    {
                        fi = i;
                        break;
                    }
                    else
                    {
                    }
                }
                for (int i = n - 1; i >= 0; i--)
                {
                    int alt = n - 1 - i;
                    if (s[i] == ele && alt % 3 == 0)
                    {
                        li = i;
                        break;
                    }
                    else
                    {
                    }
                }

                if (fi < li)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
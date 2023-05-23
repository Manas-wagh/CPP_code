#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        int cw = INT32_MIN;
        int n = arr.size();
        int life = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == cw)
            {
                life++;
            }
            else if (life == 0)
            {
                cw = arr[i];
                life = 1;
            }
            else
            {
                life--;
            }
        }
        return cw;
    }
};

// majority ele 2

class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        int cw1 = INT32_MIN;
        int cw2 = INT32_MIN;
        int n = arr.size();
        int life1 = 0;
        int life2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == cw1)
            {
                life1++;
            }
            else if (arr[i] == cw2)
            {
                life2++;
            }
            else if (life1 == 0)
            {
                cw1 = arr[i];
                life1 = 1;
            }
            else if (life2 == 0)
            {
                cw2 = arr[i];
                life2 = 1;
            }
            else
            {
                life1--;
                life2--;
            }
        }
        int winner = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (cw1 == arr[i])
            {
                cnt++;
            }
        }
        if (cnt > n / 2)
        {
            winner = cw1;
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (cw2 == arr[i])
            {
                cnt++;
            }
        }
        if (cnt > n / 2)
        {
            winner = cw2;
        }
        cnt = 0;
        return winner;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
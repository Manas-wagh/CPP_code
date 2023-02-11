#include <bits/stdc++.h>
using namespace std;

int isPrime(int A)
{

    if (A == 1 || A == 0)
    {
        return 0;
    }
    if (A < 0)
    {
        return 0;
    }
    int i;
    for (i = 2; i * i <= A; i++)
    {
        if (A % i == 0)
            return 0;
    }
    return 1;
}

// finding all factors

vector<int> allFactors(int A)
{

    vector<int> ans;
    int i;
    int c;
    if (A == 1)
    {
        ans.push_back(1);
        return ans;
    }
    for (i = 1; i * i <= A; i++)
    {
        if (A % i == 0)
        {
            ans.push_back(i);
            if (i * i != A)
            {
                c = i;
            }
        }
    }

    for (c = c; c > 0; c--)
    {
        if (A % c == 0)
        {
            ans.push_back(A / c);
        }
    }

    return ans;
}

int main()
{
    return 0;
}
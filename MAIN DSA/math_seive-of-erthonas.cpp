#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int A)
{
    vector<bool> isprime(A + 1, true);
    for (int i = 2; i * i <= A; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= A; j = j + i)
            {
                isprime[j] = false;
            }
        }
    }
    vector<int> ans;
    for (int a = 2; a <= A; a++)
    {
        if (isprime[a])
        {
            ans.push_back(a);
        }
    }
    return ans;
}
int main()
{
    return 0;
}
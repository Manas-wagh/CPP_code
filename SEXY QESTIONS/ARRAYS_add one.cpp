#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &A)
{
    int carr = 1;
    vector<int> ppl(1, 1);
    for (int i = A.size() - 1; i > 0; i--)
    {
        int c = A[i];
        A[i] = (A[i] + carr) % 10;
        carr = (c + carr) / 10;
        }
    int ind = 0;

    while (A[ind] == 0)
    {
        ind++;
    }

    if (ind != 0)
    {
        A.erase(A.begin(), A.begin() + ind - 1);
    }

    if (carr)
    {
        A.insert(A.begin(), 1);
    }

    return A;
}

int main()
{
    vector<int> B(5, 9);
    plusOne(B);
    return 0;
}
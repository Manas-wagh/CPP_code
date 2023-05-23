#include <bits/stdc++.h>
using namespace std;

string findDigitsInBinary(int A)
{

    string ans;
    if (A == 0)
    {
        return "0";
    }
    while (A > 0)
    {
        if ((A & 1))
        {
            // ans.push_back(0);
            ans.insert(0, "1");
        }
        else
        {
            // ans.push_back(1);
            ans.insert(0, "0");
        }
        A = A >> 1;
    }
    // for(int i=ans.length()-1;i>=0;i--){

    // }
    return ans;
}

// total number of diffrent bits;
int hammingDistance(int x, int y)
{
    int c = 0;
    for (int i = 0; i <= 31; i++)
    {
        int a = (x >> i) & 1;
        int b = (y >> i) & 1;
        if (a != b)
            c++;
    }
    return c;
}

int main()
{
    return 0;
}

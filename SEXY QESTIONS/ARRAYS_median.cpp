#include <bits/stdc++.h>
using namespace std;

int median(int a1[], int a2[], int n1, int n2)
{

    int begin = 0;
    int end = n1;

    while (begin <= end)
    {
        int i1 = (begin + end) / 2;
        int i2 = ((n1 + n2 + 1) / 2) - i1;

        int min1 = (i1 == n1) ? INT_MAX : a1[i1];
        int min2 = (i1 == n2) ? INT_MAX : a2[i2];
        int max1 = (i1 == 0) ? INT_MIN : a1[i1 - 1];
        int max2 = (i1 == 0) ? INT_MIN : a2[i2 - 1];

        if (min1 >= max2 && max1 <= min2)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return ((double)min(min1, min2) + max(max1, max2)) / 2;
            }
            else
            {
                return (double)max(max1, max2);
            }
        }
        else
        {
            if (min1 < max2)
            {
                begin = i1 + 1;
            }
            else
            {
                end = i1 - 1;
            }
        }
    }
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
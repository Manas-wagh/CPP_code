#include <bits/stdc++.h>
using namespace std;

int numDistinct(string S, string T)
{
    int sLen = S.length(), tLen = T.length();
    if (sLen < tLen)
        return 0;
    if (sLen == tLen)
    {
        if (S.compare(T) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int path[tLen + 1][sLen + 1], i, j;

    for (i = 0; i <= sLen; ++i)
    {
        path[0][i] = 0;
    }
    for (j = 0; j <= tLen; ++j)
    {
        path[j][0] = 0;
    }

    for (i = 1; i <= tLen; ++i)
    {
        for (j = 1; j <= sLen; ++j)
        {
            if (T.at(i - 1) == S.at(j - 1))
            {
                if (i != 1)
                {
                    path[i][j] = path[i][j - 1] + path[i - 1][j - 1];
                }
                else
                {
                    path[i][j] = path[i][j - 1] + 1;
                }
            }
            else
            {
                path[i][j] = path[i][j - 1];
            }
        }
    }
    return path[tLen][sLen];
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
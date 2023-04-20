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
        int manas[2][n];
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                manas[0][i] = 1;
            }
            else
            {
                manas[0][i] = -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                manas[1][i] = -1;
            }
            else
            {
                manas[1][i] = 1;
            }
        }

        manas[0][0] = (2 * n) - 1;
        manas[1][n - 1] = (2 * n);
        int k = (2 * n) - 2;
        int zz = 0;
        for (int i = 0; i < n - 1; i = i + 2)
        {

            manas[1][i] = (2 * zz) + 1;
            zz++;
        }
        for (int i = 1; i < n - 1; i = i + 2)
        {

            manas[1][i] = (2 * zz) + 1;
            zz++;
        }
        zz = 1;
        for (int i = 1; i < n; i = i + 2)
        {

            manas[0][i] = (2 * zz);
            zz++;
        }
        for (int i = 2; i < n - 1; i = i + 2)
        {

            manas[0][i] = (2 * zz);
            zz++;
        }
        // cout<<endl;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << manas[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
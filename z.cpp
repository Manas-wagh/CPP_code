#include <bits/stdc++.h>
using namespace std;

string solve(string sec, string ges)
{
    int hash[10] = {0};
    int bull = 0;
    int cow = 0;
    for (int i = 0; i < sec.size(); i++)
    {
        hash[sec[i] - 48] += 1;
    }

    for (int i = 0; i < sec.size(); i++)
    {
        if (ges[i] == sec[i] && hash[ges[i] - 48] > 0)
        {
            bull++;
            hash[ges[i] - 48]--;
        }
        else if (ges[i] != sec[i] && hash[ges[i] - 48] > 0)
        {
            cow++;
            hash[ges[i] - 48]--;
        }
        else
        {
        }
    }
    return to_string(bull) + "A" + to_string(cow) + "B";
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        cout << solve("6020943525972", "7157627311068");
    }

    return 0;
}
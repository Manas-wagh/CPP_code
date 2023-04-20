#include <bits/stdc++.h>
using namespace std;

string Finalstr = "";
void lsubstring(string s)

{

    int ans = 0;
    int hsh1[26] = {0};
    int hsh2[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        hsh1[s[i] - 'a']++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        hsh2[s[i] - 'A']++;
    }
    bool no_break = true;
    for (int i = 0; i < s.length(); i++)
    {
        int b = 0;
        if (int(s[i]) >= 97)
        {
            b = int(s[i]) - 97;
        }
        else if (int(s[i]) < 97)
        {
            b = int(s[i]) - 65;
        }
        if ((hsh1[b] == 0 && hsh2[b] != 0) || (hsh2[b] == 0 && hsh1[b] != 0))
        {
            ans = i;
            string left = s.substr(0, i);
            string right = s.substr(i + 1, s.length() - i + 1);
            lsubstring(left);
            lsubstring(right);
            no_break = false;
            break;
        }
    }

    if (no_break == true && s.length() > Finalstr.length())
    {
        Finalstr = s;
        return;
    }
    else
    {
        return;
    }
}

int main()
{
    string s;
    cin >> s;
    lsubstring(s);
    cout << Finalstr;
    return 0;
}
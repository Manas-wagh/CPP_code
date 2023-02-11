#include <bits/stdc++.h>

using namespace std;
vector<string> v;
string longestNiceSubstring(string s)
{
    map<int, int> mp;
    for (int i = 0; i < s.length(); ++i)
        mp[int(s[i])]++;
    vector<int> def;
    def.push_back(-1);
    for (int i = 0; i < s.length(); ++i)
    {
        if (int(s[i]) < 97 && mp[int(s[i])] && !mp[s[i] - 'A' + 97])
            def.push_back(i);
        else if (int(s[i]) >= 97 && mp[int(s[i])] && !mp[s[i] - 'a' + 65])
            def.push_back(i);
    }
    def.push_back(s.length());
    if (def.size() == 2)
    {
        v.push_back(s);
        return s;
    }
    for (int i = 0; i < def.size() - 1; ++i)
    {
        int l = def[i] + 1, r = def[i + 1] - 1;
        string p = s.substr(l, r - l + 1);
        // cout << p << endl;
        longestNiceSubstring(p);
    }
    int l = 0;
    v.push_back("");
    string ans;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].length() > l)
        {
            l = v[i].length();
            ans = v[i];
        }
    }
    return ans;
}

int main()
{

    cout << longestNiceSubstring("YazaAay");

    return 0;
}
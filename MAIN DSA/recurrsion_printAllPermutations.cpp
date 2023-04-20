#include <bits/stdc++.h>
using namespace std;

void permute(string str, int l, int h)
{

    if (l == h)
    {
        cout << str << endl;
        return;
    }
    for (int i = l; i < h + 1; i++) // sabko bithane ke liye
    {
        swap(str[l], str[i]);   // jispe hei usko bithaao
        permute(str, l + 1, h); // phir uske baad valon ke liye chalo
        swap(str[l], str[i]);   // phir pehle bethe hue ko uthao taki dusra beth pai
    }
}

int main()
{

    return 0;
}
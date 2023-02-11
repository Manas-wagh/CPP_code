#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int c1 = 0, a[1000];
void build(int i)
{
    if (i != 0)
    {
        if (c1 < i)
        {
            c1 = i;
        }
        int p;
        cout << "Please enter the node: ";
        cin >> p;
        a[i] = p;
        string s;
        cout << "Does " << p << " has left subtree? ";
        cin >> s;
        if (s == "y")
        {
            build(2 * i);
        }
        else
            build(0);
        string t;
        cout << "Does " << p << " has right subtree? ";
        cin >> t;
        if (t == "y")
        {
            build(2 * i + 1);
        }
        else
            build(0);
    }
}
int ancestor(int b[], int x, int y)
{
    int a, d, ind = 0;
    for (int i = 1; i <= c1; i++)
    {
        if (b[i] == x)
        {
            a = i;
        }
        else if (b[i] == y)
        {
            d = i;
        }
    }
    while (1)
    {
        if (a == d)
        {
            ind = 1;
            break;
        }
        else if (d > a)
            d = d / 2;
        else if (a > d)
        {
            a = a / 2;
        }
    }
    return b[a];
}
int main()
{
    build(1);
    cout << "Please enter the value of nodes: ";
    int m, o;
    cin >> m >> o;
    cout << "The ancestor node is: " << ancestor(a, m, o) << endl;
    return 0;
}
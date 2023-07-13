#include <bits/stdc++.h>
using namespace std;

// segment tress are range query based approch
// its pictorially tree, but actually its array and maintained like complete binary tree;
// absent leaves of last lvls are represented with blank or x;
// childs: 2i+1 and 2i+2 and parent= floor((i-1)/2);
// any node stores the result of required operation in its range;
// size of array= 2n-1 if n is power of 2 (n is input arr size);
// else its 2x -1 whwere x is smalllest 2 ki power greter than n;

// for both casess we can directly use 4n (upper bound space);

// below is implemnented for sum query
int construct(int ss, int se, int si, vector<int> &inputarray, vector<int> &segmenttree) // pehle do arr ke ind and next wala tree ka
{
    if (ss == se)
    {
        segmenttree[si] = inputarray[ss];
        return segmenttree[si];
    }
    int mid = (ss + se) / 2;
    segmenttree[si] = construct(ss, mid, 2 * si + 1, inputarray, segmenttree) + construct(mid + 1, se, 2 * si + 2, inputarray, segmenttree);
    return segmenttree[si];
}

int getsum(int ss, int se, int qs, int qe, int si, vector<int> &inputarray, vector<int> &segmenttree)
{
    if (qs > se || qe < ss)
    {
        return 0;
    }
    if (qs <= ss && qe >= se)
    {
        return segmenttree[si];
    }
    int mid = (ss + se) / 2;
    return getsum(ss, mid, qs, qe, 2 * si + 1, inputarray, segmenttree) + getsum(mid + 1, se, qs, qe, 2 * si + 2, inputarray, segmenttree);
}
void update(int ss, int se, int i, int diff, int si, vector<int> &inputarray, vector<int> &segmenttree)
{
    // here i is kis index pei update karna hei, and diff is update val- curr val; ye apan add karenge
    if (i < ss || i > se)
    {
        return;
    }
    segmenttree[si] += diff;
    if (se > ss)
    {
        int mid = (ss + se) / 2;
        update(ss, mid, i, diff, 2 * si + 1, inputarray, segmenttree);
        update(mid + 1, se, i, diff, 2 * si + 2, inputarray, segmenttree);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> inputarray{10, 20, 30, 40};
    vector<int> segmenttree(4 * n);
    construct(0, n - 1, 0, inputarray, segmenttree);
    cout << getsum(0, n - 1, 0, n - 2, 0, inputarray, segmenttree);
    cout << endl;
    update(0, n - 1, 2, 10, 0, inputarray, segmenttree);
    cout << getsum(0, n - 1, 0, n - 1, 0, inputarray, segmenttree);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// used to find MST and its a freddy algo
// 1st sort all edges accn to the weight
// travel all edges in sorted form and IGNORE all those who have cycle
// time complexity= O(Elog(E))

class edge
{
public:
    int src;
    int dest;
    int weight;

    edge() {}

    edge(int a, int b, int c)
    {
        src = a;
        dest = b;
        weight = c;
    }
};
class DSU
{
private:
public:
    int size;
    int *parent = new int[size];
    int *rank = new int[size];
    DSU()
    {
        size = 1000;
        for (int i = 0; i < 1000; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    DSU(int s)
    {
        size = s;
        for (int i = 0; i < s; i++) // intializing parent as themselves
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findopt(int x)
    {
        if (x == parent[x])
        {
            return x;
        }
        else
        {
            parent[x] = findopt(parent[x]); // ie tab tak upar jao jab tak root na mil jaye
            return parent[x];
        }
    }
    void unionopt(int x, int y)
    {
        int x_rep = findopt(x); // dono ke roots
        int y_rep = findopt(y);
        if (x_rep == y_rep)
        {
            return;
        }
        if (rank[x_rep] > rank[y_rep])
        {
            parent[y_rep] = x_rep;
        }
        else if (rank[x_rep] < rank[y_rep])
        {
            parent[x_rep] = y_rep;
        }
        else
        {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
};
bool compare(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}

int krushkal(vector<edge> &arr, int v)
{
    sort(arr.begin(), arr.end(), compare);
    int res = 0;
    DSU MST(v);
    for (int i = 0, s = 0; s < v - 1; i++)
    {
        int x = arr[i].src;
        int y = arr[i].dest;
        if (x != y)
        {
            res += arr[i].weight;
            MST.unionopt(x, y);
            s++;
        }
    }
    return res;
}

int main()
{
    return 0;
}
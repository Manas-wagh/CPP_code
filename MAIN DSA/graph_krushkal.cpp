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

bool compare(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}


int main()
{
    return 0;
}
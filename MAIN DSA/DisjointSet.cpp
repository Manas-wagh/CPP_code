#include <bits/stdc++.h>
using namespace std;
// it literrally means sets with no intersections
// each set here is a tree
// so total collection is called forest
// implemented using arrays

// each set has a representative..so in find operatition, for any ele in that set, we get its reprentative
// ie if(find(a)==find(b))=> they are one same set;
// numbering is 0 indexed;
// initially each node is seperate ds, so their parent is themselves
// rank is basically height of that node from base
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
    // naive find;
    int find(int x) // returnns the representative
    {
        if (x == parent[x])
        {
            return x;
        }
        else
        {
            return find(parent[x]); // ie tab tak upar jao jab tak root na mil jaye
        }
    }
    // find with path compression
    // path compression furthur makes tc O(1) after initially ek baar execute ho chuka ho uss ele ke liye
    // here jiske liye find call kar rahe usko end mei sidha root pei chipka dete hei
    // exact tc is O(m*alpha); whre alpha<=4(called as inverserse ackarmann) and m=total operations
    // ie for one operation its constant
    int findopt(int x)
    {
        if (x == parent[x])
        {
            return x;
        }
        else
        {
            parent[x] = find(parent[x]); // ie tab tak upar jao jab tak root na mil jaye
            return parent[x];
        }
    }
    // naive union
    void unions(int x, int y) // combine two tress
    {
        int x_rep = find(x); // dono ke roots
        int y_rep = find(y);
        // now make root of y as child of root of x, ie now represent is x ka root
        if (x_rep == y_rep)
        {
            return;
        }
        parent[y_rep] = x_rep;
    }
    // union by rank
    // helps making find in nlogn;
    // jiske rank jyada hoti hei usme dusre ko ghusate hei
    void unionopt(int x, int y)
    {
        int x_rep = find(x); // dono ke roots
        int y_rep = find(y);
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
            // upar ke dono case mei height nahi badh rahi thi
            // but iss case mei badhegi ek sei
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
};

int main()
{
    DSU manas(5);
    // cout << manas.parent[4];
    manas.unionopt(3, 4);
    manas.unionopt(2, 3);
    cout << manas.find(2);
    return 0;
}
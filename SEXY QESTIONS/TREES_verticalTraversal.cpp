#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map<int, map<int, vector<int>>> m;

void vertical(TreeNode *A, int level, int height)
{
    if (A == NULL)
    {
        return;
    }
    m[level][height].push_back(A->val);
    vertical(A->left, level - 1, height + 1);
    vertical(A->right, level + 1, height + 1);
}

vector<vector<int>> verticalOrderTraversal(TreeNode *A)
{
    m.clear();
    vector<vector<int>> ans;
    vertical(A, 0, 0);
    for (auto i = m.begin(); i != m.end(); i++)
    {
        vector<int> temp;
        for (auto j = i->second.begin(); j != i->second.end(); j++)
        {
            for (int k = 0; k < j->second.size(); k++)
            {
                temp.push_back(j->second[k]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{

    int t;
    cin >> t;
    queue<int> s;

    while (t--)
    {
    }
    return 0;
}
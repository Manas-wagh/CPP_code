#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool solve(TreeNode *root, int k, unordered_set<int> &st)
{

    if (!root)
        return false;

    if (st.find(k - root->val) != st.end())
        return true;

    st.insert(root->val);

    return solve(root->left, k, st) or solve(root->right, k, st);
}

int t2Sum(TreeNode *root, int k)
{

    unordered_set<int> st;

    return solve(root, k, st);
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
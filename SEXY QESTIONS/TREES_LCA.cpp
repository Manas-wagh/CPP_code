#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool findPath(TreeNode *root, vector<int> &path, int k)
{
    // base case
    if (root == NULL)
        return false;

    // Store this node in path vector. The node will be removed if
    // not in path from root to k
    path.push_back(root->val);

    // See if the k is same as root's key
    if (root->val == k)
        return true;

    // Check if k is found in left or right sub-tree
    if ((root->left && findPath(root->left, path, k)) ||
        (root->right && findPath(root->right, path, k)))
        return true;

    // If not present in subtree rooted with root, remove root from
    // path[] and return false
    path.pop_back();
    return false;
}

int lca(TreeNode *A, int val1, int val2)
{

    vector<int> path1, path2;

    // Find paths from root to n1 and root to n1. If either n1 or n2
    // is not present, return -1
    if (!findPath(A, path1, val1) || !findPath(A, path2, val2))
        return -1;

    /* Compare the paths to get the first different value */
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); ++i)
        if (path1[i] != path2[i])
            break;
    return path1[i - 1];
}

int main()
{

    int t;
    cin >> t;
    // queue<int> st;

    while (t--)
    {
    }
    return 0;
}
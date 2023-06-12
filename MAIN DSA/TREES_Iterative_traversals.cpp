#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//  INORDER
vector<int> solve(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        ans.push_back(curr->val);
        curr = curr->right;
    }
    return ans;
}

// PREORDER

void solve(TreeNode *root, vector<int> &ans)
{
    if (!root) // if take true for not null and false for null;
    {
        return;
    }
    stack<TreeNode *> s;
    s.push(root);
    while (s.empty() == false)
    {
        TreeNode *curr = s.top();
        ans.push_back(curr->val);
        s.pop();
        if (curr->right != NULL)
        {
            s.push(curr->right);
        }
        if (curr->left != NULL)
        {
            s.push(curr->left);
        }
    }
}

// POSTORDER

vector<int> postorderTraversal(TreeNode *A)
{
    vector<int> ret;
    if (!A)
    {
        return ret;
    }
    stack<TreeNode *> S, T;

    S.push(A);
    while (!S.empty())
    {
        TreeNode *temp = S.top();
        S.pop();
        T.push(temp);
        if (temp->left)
            S.push(temp->left);
        if (temp->right)
            S.push(temp->right);
    }
    while (!T.empty())
    {
        TreeNode *temp = T.top();
        T.pop();
        ret.push_back(temp->val);
    }
    return ret;
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
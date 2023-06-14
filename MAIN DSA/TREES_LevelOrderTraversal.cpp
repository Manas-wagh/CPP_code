#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// normal level order

void lvlorder(TreeNode *root, vector<int> &order)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (q.empty() == false)
    {
        TreeNode *curr = q.front();
        q.pop();
        order.push_back(curr->val);
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

// lvl order line by line
//
// method 1: simply maintain a null pointer in que such that after each lvl is process we push it.
// its O(N) and space is O(width)

void lvlorderlbl(TreeNode *root, vector<vector<int>> &order)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> q;
    vector<int> temp;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            order.push_back(temp);
            temp.clear();
            q.push(NULL);
            continue;
        }
        temp.push_back(curr->val);
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

// method 2: here we simply run two loops, inner loop to print within lvl and outer to maintane lvl;
// same time and space

void lvlorderlbl2(TreeNode *root, vector<vector<int>> &order)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> q;
    vector<int> temp;
    q.push(root);
    while (q.empty() == false)
    {
        int cnt = q.size();
        for (int i = 0; i < cnt; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            temp.push_back(curr->val);
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
        order.push_back(temp);
        temp.clear();
    }
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
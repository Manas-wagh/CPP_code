#include <bits/stdc++.h>
using namespace std;
#define ll long long
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *balanceBST(vector<int> v, int l, int r)
    {
        if (r < l)
            return nullptr;
        if (r == l)
            return (new TreeNode(v[r]));
        int mid = (l + r) / 2;
        TreeNode *t = new TreeNode(v[mid]);
        t->left = balanceBST(v, l, mid - 1);
        t->right = balanceBST(v, mid + 1, r);
        return t;
    }
};

void displayInOrder(TreeNode *root)
{
    if (!root)
    {
        cout << "null"
             << " ";
        return;
    }
    cout << root->val << " ";
    displayInOrder(root->left);
    displayInOrder(root->right);
}
vector<int> InOrder(TreeNode *root)
{
    if (!root)
    {
        return {};
    }
    vector<int> vect2(InOrder(root->left));
    vect2.push_back(root->val);
    vector<int> second = InOrder(root->right);
    move(second.begin(), second.end(), back_inserter(vect2));
    return vect2;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        // Test Case 1
        TreeNode *d = new TreeNode(4);
        TreeNode *c = new TreeNode(3, NULL, d);
        TreeNode *b = new TreeNode(2, NULL, c);
        TreeNode *a = new TreeNode(1, NULL, b);
    }
}
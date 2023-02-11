#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
} *root = NULL;

// Recurrsive way of insertion in BST
Node *Rinsert(Node *p, int key)
{

    Node *t;
    if (p == NULL)
    {
        t = new Node();
        t->data = key;
        t->right = t->left = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->left = Rinsert(p->left, key);
    }
    else if (key > p->data)
    {
        p->right = Rinsert(p->right, key);
    }
    return t;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int dl = diameter(root->left);
    int dr = diameter(root->right);
    int cur = height(root->right) + height(root->left);
    return max(cur, max(dl, dr));
}

int main()
{
    struct Node *temp;
    root = Rinsert(root, 20);
    Rinsert(root, 10);
    Rinsert(root, 30);
    Rinsert(root, 40);
    cout << "Diameter of given tree \n";
    cout << diameter(root) << endl;

    return 0;
}
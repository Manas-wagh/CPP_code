#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

bool search(TrieNode *root, string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        int ind = s[i] - 'a';
        if (root->child[ind] == NULL)
        {
            return false;
        }
        root = root->child[ind];
    }
    return root->isEnd;
}

void insert(TrieNode *root, string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        int ind = s[i] - 'a';
        if (root->child[ind] == NULL)
        {
            root->child[ind] = new TrieNode();
        }
        root = root->child[ind];
    }
    root->isEnd = true;
}

bool isempty(TrieNode *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i] != NULL)
        {
            return false;
        }
    }
    return true;
}

TrieNode *deletekey(TrieNode *root, string &s, int cnt)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (cnt == s.size())
    {
        root->isEnd = false;
        if (isempty(root))
        {
            delete (root);
            root = NULL;
        }
        return root;
    }
    int ind = s[cnt] - 'a';
    root->child[ind] = deletekey(root->child[ind], s, cnt + 1);
    if (isempty(root) && root->isEnd == false)
    {
        delete (root);
        root = NULL;
    }
    return root;
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
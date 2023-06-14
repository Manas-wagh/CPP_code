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

vector<int> solve(string A, vector<string> &B)
{
    vector<int> ans;
    TrieNode *root = new TrieNode();
    int i = 0;
    int j = 0;
    while (j < A.size())
    {
        if (A[j] == '_')
        {
            insert(root, A.substr(i, j - i));
            i = j + 1;
        }
        j++;
    }
    vector<pair<int, int>> cnt;

    for (int m = 0; m < B.size(); m++)
    {
        cnt.push_back({0, m});
        j = 0;
        i = 0;
        while (j < B[m].size())
        {
            if (A[j] == '_')
            {
                if (search(root, B[m].substr(i, j - i)))
                {
                    cnt[cnt.size() - 1].first++;
                }
                i = j + 1;
            }
            j++;
        }
    }
    sort(cnt.begin(), cnt.end());
    for (int i = cnt.size() - 1; i > -1; i--)
    {
        ans.push_back(cnt[i].second);
    }

    return ans;
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
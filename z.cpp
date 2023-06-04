#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

string simplifyPath(string arr)
{
    stack<char> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == '/')
        {
            if (s.empty() == true)
            {
                s.push('/');
            }
            else
            {
                if (s.top() != '/')
                {
                    s.push('/');
                }
            }
        }
        else if (arr[i] == '.')
        {
            while (s.empty() == false && s.top() != '/')
            {
                s.pop();
            }
            if (s.empty() == false)
            {
                s.pop();
            }
        }
        else
        {
            s.push(arr[i]);
        }
    }
    if (s.empty() == false && s.top() == '/')
    {
        s.pop();
    }
    string str = "";
    stack<char> temp;
    while (s.empty() != true)
    {
        char x = s.top();
        s.pop();
        temp.push(x);
    }
    while (temp.empty() != true)
    {
        char x = temp.top();
        str.push_back(x);
        temp.pop();
    }
    return str;
}

int main()
{
    ListNode *A = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    A->val = 5;
    A->next = b;
    b->next = c;
    c->next = NULL;
    cout << simplifyPath("/a/./b/");
    return 0;
}
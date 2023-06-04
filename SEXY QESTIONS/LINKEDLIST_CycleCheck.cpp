#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *A)
{

    ListNode *slow = A;
    ListNode *fast = A;
    while (1)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast == NULL || fast->next == NULL)
        {
            return NULL;
        }
        else
        {
            fast = fast->next;
            if (fast == slow)
            {
                slow = A;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
            else
            {
            }
        }
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
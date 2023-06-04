#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *SortedMerge(ListNode *a, ListNode *b)
{
    ListNode *result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->val <= b->val)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

ListNode *sortList(ListNode *A)
{
    if (!A || !A->next)
        return A;

    ListNode *head, *a, *b, *slow, *fast, *ret;
    head = A;

    slow = head;
    fast = head->next;
    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    a = head;
    b = slow->next;
    slow->next = NULL;

    a = sortList(a);
    b = sortList(b);

    if (!a)
    {
        return b;
    }
    if (!b)
    {
        return a;
    }
    return SortedMerge(a, b);
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
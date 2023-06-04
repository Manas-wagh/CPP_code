#include <bits/stdc++.h>
using namespace std;

// we have to handle special case where element is inserted at head;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *A)
{
    if (!A || !A->next)
        return A;

    ListNode *newHead = new ListNode(A->val);
    ListNode *it = A->next;
    ListNode *it_inner, *next, *oldHead, *oldNext;
    while (it)
    {
        it_inner = newHead;
        next = it->next;
        if (it->val <= newHead->val)
        {
            oldHead = newHead;
            newHead = it;
            newHead->next = oldHead;
        }
        else
        {
            while (it_inner->next)
            {
                if (it->val > it_inner->val && it->val <= it_inner->next->val)
                {
                    oldNext = it_inner->next;
                    it_inner->next = it;
                    it->next = oldNext;
                }
                it_inner = it_inner->next;
            }
            if (!it_inner->next && it->val > it_inner->val)
            {
                it_inner->next = it;
                it->next = NULL;
            }
        }
        it = next;
    }
    return newHead;
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
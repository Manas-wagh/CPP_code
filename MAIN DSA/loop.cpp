#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node()
    {
        next = NULL;
    }
};

void traversal(node *head)
{
    node *p;
    p = head;
    while (head->next != p)
    {
        cout << head->data << endl;
        head = head->next;
    }
    cout << head->data << endl;
}

node *create(int no)
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    node *ptr;
    node *adrr;
    node *last = new node;
    ptr = last;

    last->data = arr[n - 1];

    for (int i = 1; i < n; i++)
    {

        node *a;
        a = new node;

        a->next = ptr;

        a->data = arr[n - i - 1];

        ptr = a;
    }
    node *head = ptr;
    last->next = ptr;
    return head;
}

void checkloop(node *head)
{
    node *p, *q;

    q = head;
    int cnt = 1;
    int cn = 0;

    while (head->next != p)
    {
        cnt++;
        head = head->next;
    }
    p = head;
    for (int i = 1; i < cnt; i++)
    {
        if (p->next == q)
        {
            cn++;
        }
        else
        {
        }
        q = q->next;
    }
    if (cn > 0)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}
int main()
{
    node *head = create(2);

    traversal(head);
    checkloop(head);
    return 0;
}
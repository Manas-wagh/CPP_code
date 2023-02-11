#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node()
    {
        next = NULL;
        prev = NULL;
    }
};
class lnkdstack
{
public:
    int data;
    lnkdstack *next;

    lnkdstack()
    {
        next = NULL;
    }
};
lnkdstack *top = NULL;
class mystack
{
public:
    int size;
    int top;
    int *arr;

    mystack()
    {
        top = -1;
    }
    mystack(int c)
    {
        top = -1;
        size = c;
        arr = new int[size];
    }
};
lnkdstack *createlnkd(int n, int arr[])
{

    lnkdstack *ptr;
    lnkdstack *last = new lnkdstack;
    top = last;
    ptr = last;
    last->next = NULL;
    last->data = arr[n - 1];

    for (int i = 1; i < n; i++)
    {

        lnkdstack *a;
        a = new lnkdstack;

        a->next = ptr;

        a->data = arr[n - i - 1];

        ptr = a;
    }
    lnkdstack *head = ptr;
    return head;
}

int isfull(mystack *s)
{
    if (s->top == s->size - 1)
    {
        cout << "stack is full" << endl;
        return 1;
    }
    else
    {
        cout << "stack is not full" << endl;
        return 0;
    }
}
int isempty(mystack *s)
{
    if (s->top == -1)
    {
        cout << "stack is empty" << endl;
        return 1;
    }
    else
    {
        cout << "stack is not empty" << endl;
        return 0;
    }
}
int isEmptylist(lnkdstack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
lnkdstack *push(lnkdstack *head, int data)
{
    lnkdstack *newEle;
    newEle = new lnkdstack;

    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = newEle;
    newEle->next = NULL;
    newEle->data = data;
    top = newEle;
    return newEle;
}
lnkdstack *pop(lnkdstack *head)
{
    if (isEmptylist(top))
    {
        cout << "list is empty" << endl;
    }
    else
    {
        lnkdstack *p;
        lnkdstack *q;
        p = head;
        q = head->next;
        if (q == NULL)
        {
            free(p);
            top = NULL;
        }
        else
        {
            while (q->next != NULL)
            {
                p = p->next;
                q = q->next;
            }
            p->next = NULL;
            top = p;
            free(q);
        }
    }

    return head;
}

// int isFull(struct Node *top)
// {
//     lnkdstack *p = new lnkdstack;
//     if (p == NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
void traversalstack(mystack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        cout << s->arr[i] << endl;
    }
}
mystack *createstack()
{
    int t, act;

    cin >> t;
    cin >> act;
    mystack *s = new mystack(t);

    for (int i = 0; i < act; i++)
    {
        cin >> s->arr[i];
    }
    s->top = s->top + act;
    return s;
}
void traversal(node *head)
{

    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
// void traversal(lnkdstack *head)
// {
//     lnkdstack *p = head;
//     while (p != NULL)
//     {
//         cout << p->data << endl;
//         p = p->next;
//     }
// }
void traversalcircle(node *head)
{
    node *p;
    p = head;
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != head);
}
node *insertatfront()
{
}
node *create(int n, int arr[])
{

    node *ptr;
    node *last = new node;
    ptr = last;
    last->next = NULL;
    last->prev = NULL;
    last->data = arr[n - 1];

    for (int i = 1; i < n; i++)
    {

        node *a;
        a = new node;

        a->next = ptr;
        ptr->prev = a;

        a->data = arr[n - i - 1];

        ptr = a;
    }
    node *head = ptr;
    head->prev = NULL;
    return head;
}
node *createcircle(int n, int arr[])
{

    node *ptr, *y;
    node *last = new node;
    ptr = last;
    y = last;
    last->next = NULL;
    last->prev = NULL;
    last->data = arr[n - 1];

    for (int i = 1; i < n; i++)
    {

        node *a;
        a = new node;

        a->next = ptr;
        ptr->prev = a;

        a->data = arr[n - i - 1];

        ptr = a;
    }
    node *head = ptr;
    head->prev = y;
    y->next = head;
    return head;
}
node *nhead(node *head, int index)
{
    node *p;
    p = head;
    for (int i = 1; i < index; i++)
    {
        p = p->next;
    }
    head = p;
    return head;
}
void deleteindex(node *head, int index)
{
    node *p, *q;
    p = head;
    q = head->next;
    for (int i = 1; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    q->next->prev = p;
    free(q);
}
node *deletehead(node *head)
{

    node *temp = head;
    head = head->next;
    free(temp);
    head->prev = NULL;
    return head;
}

node *deletelast(node *head)
{
    node *p;
    node *q;
    p = head;
    q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}
node *insertFirst(node *head, int data)
{

    node *newEle;
    newEle = new node;
    newEle->data = data;
    newEle->next = head;
    head->prev = newEle;
    head = newEle;
    return head;
}

node *insertLast(node *head, int data)
{
    node *newEle;
    newEle = new node;
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newEle;
    newEle->prev = p;
    newEle->next = NULL;
    newEle->data = data;
    return head;
}

node *insertAtIndex(node *head, int index, int data)
{

    node *newEle;
    newEle = new node;
    node *p = head;
    for (int i = 1; i < index - 1; i++)
    {
        p = p->next;
    }
    newEle->next = p->next;
    p->next = newEle;
    newEle->prev = p;
    newEle->next->prev = newEle;
    newEle->data = data;
    return head;
}
node *reversal(node *head)
{

    node *p;
    node *q;
    node *r;
    node *adrr;
    p = NULL;
    q = head;

    while (q->next != NULL)
    {
        r = q->next;
        q->next = p;
        q->prev = r;
        p = q;
        q = r;
    }
    q->next = p;
    q->prev = r;

    head = q;
    return head;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 1

    // node *head = create(n, arr);
    // traversal(head);

    // head = deletehead(head);
    // head = deletelast(head);
    // traversal(head);
    // deleteindex(head, 3);
    // traversal(head);

    // head = insertFirst(head, 8);
    // traversal(head);
    // head = insertLast(head, 8);
    // traversal(head);
    // head = insertAtIndex(head, 3, 8);
    // traversal(head);

    // 2

    // head = reversal(head);
    // traversal(head);

    // 3

    node *head = createcircle(n, arr);
    traversalcircle(head);
    head = nhead(head, 3);
    traversalcircle(head);

    // 4
    // mystack *s;
    // s = createstack();
    // traversalstack(s);

    // 5

    // int n;
    // cin >> n;
    // int arr[n];

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // lnkdstack *head = createlnkd(n, arr);
    // traversal(head);

    // head = push(head, 6);
    // traversal(head);

    // head = pop(head);
    // traversal(head);
    // head = pop(head);
    // traversal(head);
    // head = pop(head);
    // traversal(head);
    // head = pop(head);
    // traversal(head);
    // head = pop(head);

    // 6

    return 0;
}
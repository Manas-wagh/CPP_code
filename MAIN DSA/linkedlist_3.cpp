#include <bits/stdc++.h>
#include <iostream>
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

    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
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

node *create(int n, int arr[])
{

    node *ptr;
    node *last = new node;
    ptr = last;
    last->next = NULL;
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
    return head;
}

void deletelist(node *head)
{

    node *p;
    node *q;
    p = head;
    q = head->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = q->next;
    }
    cout << "deleted";
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
        p = q;
        q = r;
    }
    q->next = p;
    head = q;
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
    free(q);
}
node *deletehead(node *head)
{

    node *temp = head;
    head = head->next;
    free(temp);
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
node *deletexy(node *head)
{
    int y;
    cin >> y;
    for (int i = 2; i < y; i++)
    {

        deleteindex(head, i);
    }
    node *xyhead = deletehead(head);
    return xyhead;
}

void merge(int n, int arr[], int m, int arr2[])
{
    int c = m + n;
    int newarr[c];

    for (int i = 0; i < c; i++)
    {
        if (i % 2 == 0)
        {
            newarr[i] = arr[i / 2];
        }
        else
        {
            newarr[i] = arr2[i / 2];
        }
    }
    node *extrahead = create(c, newarr);
    traversal(extrahead);
}

void checkloop(node *head)
{
    node *p, *q;

    p = head;
    q = head->next;
    int a = 0, b = 0, cnt = 0;
    while (1)
    {
        b++;

        for (int n = 0; n < b; n++)
        {
            if (q->next == p)
            {

                cnt++;
                p = p->next;
                break;
            }
            else
            {
                p = p->next;
            }
            a++;
        }

        p = head;
        if (a == b)
        {
        }
        else
        {
            break;
        }
        a = 0;

        if (q->next != NULL)
        {
            q = q->next;
        }
        else
        {
            break;
        }
    }
    if (cnt == 0)
    {
        cout << "no" << endl;
    }
    else
    {
        cout << "yes" << endl;
    }
}
node *createcircle(int n, int arr[])
{

    node *ptr;
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
    last->next = NULL;
    return head;
}
node *deleteduplicate(node *head, int n)
{
    node *p, *q, *r, *t;
    p = head;
    t = head;
    q = head->next;
    r = q->next;
    int a = 2;
    int b = a;

    while (t->next != NULL)
    {

        while (q->next != NULL)
        {

            if (p->data == q->data)
            {
                if (q->next == NULL)
                {
                    deletelast(head);
                }
                else
                {
                    t->next = q->next;
                    free(q);
                }
                q = r;
                r = r->next;

                a++;
            }
            else
            {

                q = r;
                r = r->next;
                t = t->next;
                a++;
            }
        }
        b++;
        a = b;

        p = p->next;
        t = p;
        q = p->next;
        r = q->next;
    }

    // p = head;
    // while (p->next == q)
    // {

    //     if (q->data == p->data)
    //     {
    //         deletelast(head);
    //     }
    //     p = p->next;
    // }

    return head;
}
node *delete_duplicate_ele(node *head)
{
    int hash[1000]{0};
    node *temp = head;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *t = head;
    while (temp->next != NULL)
    {
        if (hash[temp->data] != 0)
        {
            t->next = temp->next;
            free(temp);
            temp = t->next;
            continue;
        }
        hash[temp->data]++;
        t = temp;
        temp = temp->next;
    }
    if (hash[temp->data] != 0)
    {
        t->next = temp->next;
        free(temp);
        temp = t->next;
    }
    return head;
}
node *unionset(node *head, node *head1)
{
    node *p, *q;
    p = head;
    q = head1;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = head1;
    while (q->next != NULL)
    {
        q = q->next;
    }
    node *uhead = delete_duplicate_ele(head);

    return uhead;
}
void intersectset(node *head, node *head2)
{
    int N = 100000;
    int hsh[N] = {0};
    node *temp = head;
    node *temp2 = head2;
    while (temp->next != NULL)
    {
        hsh[temp->data]++;
        temp = temp->next;
    }
    hsh[temp->data]++;
    while (temp2->next != NULL)
    {
        if (hsh[temp2->data] > 0)
        {
            cout << temp2->data << " ";
            hsh[temp2->data] = 0;
        }
        temp2 = temp2->next;
    }
    if (hsh[temp2->data] > 0)
    {
        cout << temp2->data << " ";
        hsh[temp2->data] = 0;
    }
}
node *intersectionset(node *head, node *head1)
{
    node *p, *q;
    node *nhead = delete_duplicate_ele(head);
    node *nhead1 = delete_duplicate_ele(head1);
    // p = nhead;
    // q = nhead1;
    // int c, d;
    // c = 1;
    // d = 1;
    // while (p->next != NULL)
    // {
    //     p = p->next;
    //     c++;
    // }
    // while (q->next != NULL)
    // {
    //     q = q->next;
    //     d++;
    // }
    p = nhead;
    q = nhead1;
    int i = 1;

    while (p->next != NULL)
    {
        while (q->next != NULL)
        {
            if (q->data == p->data)
            {
                // arrn[i] = q->data;
                i++;
            }
            else
            {
            }
            q = q->next;
        }

        p = p->next;
    }
    int arrn[i];
    int k = 0;
    p = nhead;
    q = nhead1;
    while (p != NULL)
    {
        while (q != NULL)
        {
            if (q->data == p->data)
            {
                arrn[k] = q->data;
                k++;
            }
            else
            {
            }
            q = q->next;
        }

        p = p->next;
    }
    // if (q->data == p->data)
    // {
    //     arrn[k] = q->data;
    // }

    node *hhead = create(i, arrn);
    return hhead;
}
node *reversecircle(node *head)
{
    node *p, *q;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = NULL;
    node *chead = reversal(head);
    q = chead;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = chead;
    return chead;
}
void checkpal(node *head)
{
    node *p, *q;
    p = head;

    int c, d;
    c = 1;
    d = 1;
    while (p->next != NULL)
    {
        p = p->next;
        c++;
    }
    node *vhead = delete_duplicate_ele(head);
    q = vhead;
    while (q->next != NULL)
    {
        q = q->next;
        d++;
    }
    if (d == c / 2)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}
void check_palindrome(node *head)
{
    node *temp = head;
    node *t = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    temp = head;
    if (count % 2 == 0)
    {
        int c = 1;
        while (c < count / 2)
        {
            temp = temp->next;
            c++;
        }
        temp = temp->next;
        temp = reversal(temp);

        int g = 0;
        for (int i = 0; i < count / 2; i++)
        {
            if (temp->data == t->data)
            {
                g++;
            }
            temp = temp->next;
            t = t->next;
        }
        if (g == count / 2)
        {
            cout << "Palindrome" << endl;
        }
        else
        {
            cout << "not a palindrome" << endl;
        }
    }
    else
    {
        int c = 0;
        while (c < count / 2)
        {
            temp = temp->next;
            c++;
        }
        temp = temp->next;
        temp = reversal(temp);
        int g = 0;
        for (int i = 0; i < count / 2; i++)
        {
            if (temp->data == t->data)
            {
                g++;
            }
            temp = temp->next;
            t = t->next;
        }
        if (g == count / 2)
        {
            cout << "Palindrome" << endl;
        }
        else
        {
            cout << "not a palindrome" << endl;
        }
    }
}
void pal(int arr1[], int n)
{
    int c = 0, d = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr1[i] == arr1[n - i - 1])
        {
            c++;
        }
    }
    if (c == n / 2)
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
    // node *extrahead;
    // int n;
    // cin >> n;
    // int arr[n];

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // // 1

    // node *head = create(n, arr);
    // traversal(head);

    // // 2

    // // deletelist(head);
    // cout << endl;

    // 3

    // extrahead = deletehead(head);
    // extrahead = deletelast(head);
    // traversal(extrahead);
    // deleteindex(head, 3);
    // traversal(head);

    // 4

    // node *newhead = reversal(head);
    // traversal(newhead);

    // 5

    // node *xyhead = deletexy(head);
    // traversal(xyhead);

    // 6
    // creating 2nd linked list
    // int m;
    // cin >> m;
    // int arr2[m];

    // for (int i = 0; i < m; i++)
    // {
    //     cin >> arr2[i];
    // }
    // node *head2 = create(m, arr2);
    // traversal(head2);
    // cout << endl;

    // merge(n, arr, m, arr2);

    // 8

    // node *circlehead = createcircle(n, arr);
    // // traversalcircle(circlehead);
    // checkloop(circlehead);

    // 9

    // node *xhead = deleteduplicate(head, n);
    // traversal(xhead);

    // 10

    // check_palindrome(head);

    // 11

    // node *uhead = unionset(head, head2);
    // traversal(uhead);
    // node *uhead = intersectionset(head, head2);
    // traversal(uhead);

    // 12

    // node *chead = reversecircle(head);
    // traversalcircle(chead);
    int m = 4;
    node arrm[m];
    arrm[0].data = 10;
    arrm[1].data = 100;
    arrm[2].data = 101;
    arrm[3].data = 103;

    cout << arrm[3].data;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class lkdque
{
public:
    int data;
    lkdque *next;

    lkdque()
    {
        next = NULL;
    }
    lkdque(int d)
    {
        next = NULL;
        data = d;
    }
};
// declaring globally bcoz we want to avoid sending double pointers
lkdque *f = NULL;
lkdque *r = NULL;

void traversal(lkdque *head)
{

    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
int isempty()
{
    if (f == NULL) ////bcoz agar empty hoga toh f toh null pe hi rahega ne
    {
        // cout << "QUEUE underflow😅" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(lkdque *f)
{
    lkdque *t = new lkdque;
    if (t == NULL)
    {
        // cout << "QUEUE overflow😑" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

void enquelast(int val)
{
    lkdque *newele = new lkdque(val);

    if (newele == NULL)
    {
        cout << "FULL😂" << endl;
    }
    else
    {
        if (isempty())
        {
            f = newele; ////yaha pehle f and r ko first ele pe rakha padega bcoz aur kuch he nahi
            r = newele;
        }
        else
        {
            r->next = newele;
            r = r->next;
        }
    }
}
void enquefirst(int val)
{
    lkdque *newele = new lkdque(val);

    if (newele == NULL)
    {
        cout << "FULL😂" << endl;
    }
    else
    {
        if (isempty())
        {
            f = newele; ////yaha pehle f and r ko first ele pe rakha padega bcoz aur kuch he nahi
            r = newele;
        }
        else
        {
            newele->next = f;
            f = newele;
        }
    }
}
void dequeuefirst()
{
    if (isempty())
    {
        cout << "khatam hogaya bro😅😂" << endl;
    }
    else
    {
        lkdque *temp;
        temp = f;
        f = f->next;
        cout << temp->data << " ko uda diya yarr😂😃" << endl;

        free(temp);
    }
}
void dequeuelast()
{
    cout << 1;

    if (isempty())
    {
        cout << "khatam hogaya bro😅😂" << endl;
    }
    else
    {

        lkdque *temp = f;
        if (temp->next = NULL)
        {
            cout << temp->data << " ko uda diya yarr🙄😥" << endl;
            free(temp);
        }
        else
        {
            cout << 1;

            while (temp->next->next != NULL)
            {
                temp = temp->next;
                // cout << 1 << endl;
            }
            cout << 1 << endl;
            r = temp;
            temp = temp->next;
            cout << temp->data << " ko uda diya yarr🙄😥" << endl;
            r->next = NULL;
            free(temp);
        }
    }
}

int main()
{

    enquelast(5);
    enquelast(4);
    enquefirst(3);
    traversal(f);

    dequeuefirst();

    dequeuelast();
    traversal(f);
    dequeuelast();
    dequeuefirst();

    return 0;
}
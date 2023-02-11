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

void enque(int val)
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
void dequeue()
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
        cout << temp->data << " ko uda diya yarr🙄😥" << endl;
        free(temp);
    }
}

int main()
{

    enque(5);
    enque(4);
    enque(3);
    traversal(f);
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}
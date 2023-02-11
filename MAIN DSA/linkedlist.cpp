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
        }
        node(node *addr, int value)
        {
                next = addr;
                data = value;
        }
};

void traversal(node *cnt)
{

        while (cnt != NULL)
        {
                cout << cnt->data << endl;
                cnt = cnt->next;
        }
        cout << endl;
}

node *insertFirst(node *head, int data)
{

        node *newEle;
        newEle = new node;
        newEle->data = data;
        newEle->next = head;
        return newEle;
}

node *insertLast(node *head, int data)
{
        node *newEle;
        newEle = new node;

        while (head->next != NULL)
        {
                head = head->next;
        }
        head->next = newEle;
        newEle->next = NULL;
        newEle->data = data;
        return newEle;
}

node *insertAtIndex(node *head, int index, int data)
{

        node *newEle;
        newEle = new node;

        for (int i = 1; i < index - 1; i++)
        {
                head = head->next;
        }
        newEle->next = head->next;
        head->next = newEle;
        newEle->data = data;
        return newEle;
}

// node *insertAfterNode() {}

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
node *deleteAtIndex(node *head, int index)
{
        node *p;
        node *q;
        p = head;
        q = head->next;
        for (int i = 1; i < index - 1; i++)
        {
                p = p->next;
                q = q->next;
        }
        p->next = q->next;
        free(q);

        return head;
}
// node *deletelast(node *head)
// {

//         return head;
// }

int main()
{

        node *a, *b, *c, *d;
        node *newele, *head;
        newele = new node; // when not using a as head
        a = new node;
        b = new node;
        c = new node;
        d = new node;
        head = new node; // for inserting new head

        a->data = 10;
        head->data = 160;
        b->data = 100;
        c->data = 101;
        d->data = 102;

        head->next = a;
        a->next = b;
        b->next = c;
        c->next = d;

        // traversal(a);
        // traversal(c);

        head = insertFirst(head, 95);
        traversal(head);

        // newele = insertLast(head, 95);
        // traversal(head);

        // newele = insertAtIndex(head, 3, 95);
        // traversal(head);

        // head = deletehead(head);
        // traversal(head);

        // newele = deletelast(head);
        // traversal(head);

        // newele = deleteAtIndex(head, 3);
        // traversal(head);

        return 0;
}
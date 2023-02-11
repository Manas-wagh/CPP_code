#include <bits/stdc++.h>
using namespace std;

// head ko top bolte he......ie stack me linked list ulti hoti he
// ie insertion and deletion is performed for head. in O(1) time.


class node
{
public:
    int data;
    node *next;

    node()
    {
        next = NULL;
    }
    node(int c)
    {
        next = NULL;
        data = c;
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
int isempty(node *top)
{
    if (top == NULL)
    {
        cout << "stack underflow" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(node *top)
{
    node *t = new node;
    if (t == NULL)
    {
        cout << "stack overflow" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop(node **top)
{
    if (isempty(*top))
    {
        cout << "cant be popped" << endl;
        return 0;
    }
    else
    {
        node *temp;
        temp = *top;
        *top = (*top)->next;
        int x = temp->data;
        free(temp);
        return x;
    }
}
node *push(node *top, int c)
{
    if (isfull(top))
    {
        cout << "cant be pushed" << endl;
        return top;
    }
    else
    {
        node *temp = new node;
        temp->data = c;
        temp->next = top;
        top = temp;
        return top;
    }
}
int peek(node *top, int ind)
{
    node *temp = top;
    for (int i = 0; (i < ind - 1 && temp != NULL); i++)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        return temp->data;
    }
    else
    {
        return -1;
    }
}

int main()
{

    node *top;
    top = NULL;
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    traversal(top);

    // int poped;
    // poped = pop(&top);
    // cout << "removed element was " << poped << endl;
    // traversal(top);
    // poped = pop(&top);
    // cout << "removed element was " << poped << endl;
    // traversal(top);
    // poped = pop(&top);
    // cout << "removed element was " << poped << endl;
    // traversal(top);
    // poped = pop(&top);
    // cout << "removed element was " << poped << endl;
    // traversal(top);
    // poped = pop(&top);
    // cout << "removed element was " << poped << endl;
    // traversal(top);
    // poped = pop(&top);
    // cout << "removed element was " << poped << endl;
    // traversal(top);

    // int peeked = peek(top, 3);
    // cout << "the value at 3rd post is " << peeked << endl;

    return 0;
}
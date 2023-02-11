#include <bits/stdc++.h>
using namespace std;

class stacked
{
public:
    int top;
    int *arr;
    int size;
    stacked()
    {
        top = -1;
    };
    stacked(int s)
    {
        top = -1;
        size = s;
        arr = new int[s];
    };
};
class queued
{
public:
    stacked *final;
    int front;
    int rear;
    queued()
    {
        final = NULL;
        front = rear = -1;
    }
};
stacked *mained, *temp;
int stacktop(stacked *s)
{
    return s->arr[s->top];
}

int isempty(stacked *s)
{
    if (s->top == -1)
    {
        cout << "the stack is empty" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(stacked *s)
{
    if (s->top == s->size - 1)
    {
        cout << "the stack is full" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(stacked *s, int val)
{
    if (isfull(s))
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}
int pop(stacked *s)
{
    if (isempty(s))
    {
        cout << "stack underflow" << endl;
    }
    else
    {

        int x = s->arr[s->top];
        s->top--;
        cout << "element " << x << " was popped" << endl;
        return x;
    }
}
void enque(queued *root, int data)
{
    push(temp, data);
    while (!isempty(temp))
    {
        int x = pop(temp);
        push(mained, x);
    }
    root->final = mained;

    stacked *act;
    act = temp;
    temp = mained;
    mained = act;
    act = NULL;
}
void deque(queued *root, int data)
{
    pop(mained);
}
void traversal(stacked *s)
{
    for (int a = s->top; a >= 0; a--)
    {
        cout << s->arr[a] << endl;
    }
    cout << endl;
}

int main()
{

    queued *s;
    enque(s, 10);
    enque(s, 11);
    enque(s, 12);
    enque(s, 13);
    traversal(mained);
    return 0;
}
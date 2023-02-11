#include <bits/stdc++.h>
using namespace std;
// jo sabse pahile bhara jayega wo sab se agee rahega
// FIFO
class queued
{
public:
    int front;
    int rear;
    int size;
    int *arr;

    queued()
    {
        front = -1;
        rear = -1;
    }
    queued(int c)
    {
        front = -1;
        rear = -1;
        size = c;
        arr = new int[c];
    }
};
int isempty(queued *s)
{
    if (s->front == s->rear)
    {
        // cout << "yes" << endl;

        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(queued *s)
{
    if (s->rear == s->size - 1)
    {
        // cout << "yes" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(queued *s, int val)
{
    if (isfull(s))
    {
        cout << "queue is full" << endl;
    }
    else
    {
        s->rear++;
        s->arr[s->rear] = val;
    }
}
int dequeue(queued *s)
{
    if (isempty(s))
    {
        cout << "queue is empty" << endl;
        return s->front;
    }
    else
    {
        s->front++;
        return s->arr[s->front];
    }
}

int main()
{
    queued *s = new queued(4);
    isempty(s);
    enqueue(s, 10);
    enqueue(s, 20);
    enqueue(s, 22);
    enqueue(s, 25);
    isfull(s);

    int a;
    a = dequeue(s);
    cout << "deleted element was " << a << endl;
    a = dequeue(s);
    cout << "deleted element was " << a << endl;
    a = dequeue(s);
    cout << "deleted element was " << a << endl;
    a = dequeue(s);
    cout << "deleted element was " << a << endl;
    a = dequeue(s);

    return 0;
}
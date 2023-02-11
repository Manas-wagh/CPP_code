#include <bits/stdc++.h>
using namespace std;
// actual me circular nahi hoti...but apan usko waise visualise karte he
// circular queue is efficient than normal one bcoz we can use up the empty space created by deque
// here front-th index always remain empty//visually;

class queued
{
public:
    int front;
    int rear;
    int size;
    int *arr;

    queued()
    {
        front = 0;
        rear = 0;
    }
    queued(int c)
    {
        front = 0;
        rear = 0;
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
        // cout << "no" << endl;

        return 0;
    }
}

int isfull(queued *s)
{
    if ((s->rear + 1) % s->size == s->front)
    {
        // cout << "yes" << endl;
        return 1;
    }
    else
    {
        // cout << "no" << endl;

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
        s->rear = (s->rear + 1) % s->size;
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
        s->front = (s->front + 1) % s->size;
        return s->arr[s->front];
    }
}
int main()
{
    queued *s = new queued(5);
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

    enqueue(s, 20);
    enqueue(s, 22);
    isempty(s);

    return 0;
}
// To implement circular queue using array
#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
class myqueue
{
    int front;
    int rear;
    int sz;
    int *p;

public:
    myqueue(int x)
    {
        p = new int[x];
        front = -1;
        rear = -1;
        sz = x;
    };

    bool isempty()
    {
        return (front == -1 && rear == -1);
    };
    bool isfull()
    {
        return ((rear + 1) % sz == front);
    }
    void enqueue(int x)
    {
        if (isfull() == true)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                front = 1;
                rear = 1;
                p[front] = x;
            }
            else
            {
                rear = (rear + 1) % sz;
                p[rear] = x;
            }
        }
    };
    int dequeue()
    {
        if (isempty())
        {
            return -2;
        }
        else
        {
            int g = p[front];
            front = (front + 1) % sz;
            return g;
        }
    };
    int getrear()
    {
        if (isempty())
        {
            return -2;
        }
        else
        {
            return p[rear];
        }
    };
    int getfront()
    {
        if (isempty())
        {
            return -2;
        }
        else
        {
            return p[front];
        }
    };

    int size()
    {
        if (rear > front)
        {
            return rear - front + 1;
        }
        else
        {
            return rear - front + sz + 1;
        }
    }
    void view(int x)
    {
        cout << " " << endl;
    }
};

int main()
{
    myqueue *s = new myqueue(20);
    s->enqueue(4);
    s->enqueue(41);
    s->enqueue(42);
    s->enqueue(43);

    return 0;
}
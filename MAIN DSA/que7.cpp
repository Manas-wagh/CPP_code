// stack using queue
#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct mystack
{
    queue<int> q1, q2;
    void push(int d)
    {
        while (q1.empty() == false)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(d);
        while (q2.empty() == false)
        {
            q1.push(q2.front());
            q2.pop();
        }
    };
    int peek()
    {
        return q1.back();
    };
    int pop()
    {
        int g = q1.front();
        q1.pop();
        return g;
    };
    bool isempty()
    {
        return q1.empty();
    }
    int size()
    {
        return q1.size();
    }
};
int main()
{

    return 0;
}
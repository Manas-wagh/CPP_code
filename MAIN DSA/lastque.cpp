#include <bits/stdc++.h>
using namespace std;
#define MAX 10
int size = 0;
int arr[MAX];
class stacks
{
public:
    int top;
};
typedef struct stacks st;
void createEmptyStack1(stacks *s)
{
    s->top = -1;
}
void createEmptyStack2(stacks *s)
{
    s->top = MAX;
}
bool isempty(stacks *s)
{
    if (s->top == -1 || s->top == MAX)
    {
        return true;
    }
    return false;
}
bool isfull(stacks *s1, stacks *s2)
{
    if ((s1->top) + 1 == (s2->top))
    {
        return true;
    }
    return false;
}

void push_in_st1(stacks *s1, stacks *s2, int x)
{
    if (isfull(s1, s2))
        cout << "stack is full" << endl;

    else
    {
        (s1->top)++;
        arr[s1->top] = x;
    }
}
void push_in_st2(stacks *s1, stacks *s2, int x)
{
    if (isfull(s1, s2))
        cout << "stack is full" << endl;

    else
    {
        (s2->top)--;
        arr[s2->top] = x;
    }
}
void pop_in_st1(stacks *s)
{
    if (isempty(s))
        cout << "stack is empty" << endl;

    else
    {
        cout << "item popped is " << arr[s->top] << endl;
        (s->top)--;
    }
}
void pop_in_st2(stacks *s)
{
    if (isempty(s))
        cout << "stack is empty" << endl;

    else
    {
        cout << "item popped is " << arr[s->top] << endl;
        (s->top)++;
    }
}
int peek(stacks *s)
{
    if (isempty(s))
        return -1;
    else
    {
        return arr[s->top];
    }
}

int main()
{
    stacks *st1 = new stacks;
    createEmptyStack1(st1);

    stacks *st2 = new stacks;
    createEmptyStack2(st2);

    push_in_st1(st1, st2, 1);
    push_in_st1(st1, st2, 6);
    push_in_st1(st1, st2, 5);
    push_in_st1(st1, st2, 8);

    push_in_st2(st1, st2, 6);
    push_in_st2(st1, st2, 0);
    push_in_st2(st1, st2, 4);

    int x = peek(st2);
    cout << x << endl;

    int y = peek(st1);
    cout << y << endl;
    return 0;
}
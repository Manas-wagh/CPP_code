#include <bits/stdc++.h>
using namespace std;

// array me jo last element hota he usse hi top bolte he.....ie array is saral in stack;

class stacked
{
public:
    int size;
    int top;
    int *arr;

    stacked()
    {
        top = -1;
    }
    stacked(int s)
    {
        top = -1;
        size = s;
        arr = new int[s];
    }
};

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

// stack array me peek ke liye positioning ulti hoti he ...i.e. jaha top max hoga waha index 1 hoga;  ie index= top-position+1;

int peek(stacked *s, int pos)
{
    int sum = s->top - pos + 1;
    if (sum < 0)
    {
        cout << "invalid position" << endl;
    }
    else
    {
        return s->arr[s->top - pos + 1];
    }
}
stacked *create(stacked *s, int cnt)
{
    for (int a = 0; a < cnt; a++)
    {
        cin >> (s)->arr[a];
        s->top++;
    }
    return s;
}
void traversal(stacked *s)
{
    for (int a = 0; a <= s->top; a++)
    {
        cout << s->arr[a] << endl;
    }
    cout << endl;
}

int main()
{
    stacked *s = new stacked(50);
    s = create(s, 5);

    traversal(s);

    push(s, 10);
    traversal(s);

    int popped = pop(s);
    traversal(s);
    popped = pop(s);
    traversal(s);
    popped = pop(s);
    traversal(s);
    popped = pop(s);
    traversal(s);
    popped = pop(s);
    traversal(s);
    popped = pop(s);
    traversal(s);
    popped = pop(s);
    traversal(s);

    return 0;
}
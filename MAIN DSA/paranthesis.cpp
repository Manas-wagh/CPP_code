#include <bits/stdc++.h>
using namespace std;

class stacked
{
public:
    int size;
    int top;
    char *arr;

    stacked()
    {
        top = -1;
    }
    stacked(int s)
    {
        top = -1;
        size = s;
        arr = new char[s];
    }
};

char stacktop(stacked *s)
{
    return s->arr[s->top];
}

int isempty(stacked *s)
{
    if (s->top == -1)
    {
        // cout << "not matched" << endl;
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
void push(stacked *s, char val)
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

        char x = s->arr[s->top];
        s->top--;
        // cout << "element " << x << " was popped" << endl;
        return x;
    }
}
int paranthesis()
{
    stacked *s = new stacked(20);
    int n;
    cin >> n;
    char el;
    int c = 0;
    for (int a = 0; a < n; a++)
    {
        cin >> el;
        if (el == '(' || el == '[' || el == '{')
        {
            push(s, el);
            c++;
        }
        else if (el == ')' || el == ']' || el == '}')
        {
            if (isempty(s))
            {
                // cout << "not matched" << endl;
                break;
            }
            else
            {
                if (s->arr[s->top] == '(')
                {
                    if (el == ')')
                    {
                        pop(s);
                    }
                    else
                    {
                    }
                }
                else if (s->arr[s->top] == '{')
                {
                    if (el == '}')
                    {
                        pop(s);
                    }
                    else
                    {
                    }
                }
                else if (s->arr[s->top] == '[')
                {
                    if (el == ']')
                    {
                        pop(s);
                    }
                    else
                    {
                    }
                }
                else
                {
                }
            }
        }
        else
        {
        }
    }

    if (isempty(s) && c != 0)
    {
        cout << "paranthesis matched!" << endl;
        return 1;
    }
    else
    {
        cout << "not matched" << endl;
        return 0;
    }
}

int main()
{
    int b = paranthesis();
    return 0;
}
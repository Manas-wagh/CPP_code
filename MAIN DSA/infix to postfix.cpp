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

bool isempty(stacked *s)
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
char pop(stacked *s)
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
bool isoperator(char el)
{
    if (el == '+' || el == '-' || el == '*' || el == '/' || el == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char el)
{
    if (el == '^')
    {
        return 4;
    }
    else if (el == '*' || el == '/')
    {
        return 3;
    }
    else if (el == '+' || el == '-')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
string infpost(string infix)
{
    stacked *s = new stacked(100);
    int j = 0;
    int i = 0;
    int size = infix.length();

    string postfix = "";

    while (i < size)
    {
        if (!isoperator(infix[i]))
        {
            if (infix[i] == '(')
            {
                push(s, infix[i]);
                i++;
            }
            else if (infix[i] == ')')
            {
                while (stacktop(s) != '(')
                {
                    postfix = postfix + pop(s);
                    j++;
                }
                char kachra = pop(s);
                i++;
            }
            else
            {
                postfix = postfix + infix[i];
                j++;
                i++;
            }
        }
        else
        {
            if (infix[i] == '^')
            {
                if (precedence(infix[i]) >= precedence(stacktop(s)))
                {
                    push(s, infix[i]);
                    i++;
                }
                else
                {
                    postfix = postfix + pop(s);
                    j++;
                }
            }
            else
            {
                if (precedence(infix[i]) > precedence(stacktop(s)))
                {
                    push(s, infix[i]);
                    i++;
                }
                else
                {
                    postfix = postfix + pop(s);
                    j++;
                }
            }
        }
    }
    while (!isempty(s))
    {
        postfix = postfix + pop(s);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}
int main()
{
    string infix;
    cin >> infix;
    string out = infpost(infix);
    cout << out << endl;

        return 0;
}
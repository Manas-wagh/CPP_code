// To evaluate a given postfix expression (sequence of
// numeric operands and arithmetic operators)
#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

//
class mystack
{
public:
    int top;
    int c;
    char *a;
    mystack() {}
    mystack(int x)
    {
        top = -1;
        c = x;
        a = new char[x];
    }
    void push(char d)
    {
        if (top == c - 1)
        {
            cout << "error" << endl;
        }
        top++;
        a[top] = d;
    }
    char pop()
    {
        if (top == -1)
        {
            return '$';
        }
        char g = a[top];
        top--;
        return g;
    }
    char peek()
    {
        if (top == -1)
        {
            cout << "error" << endl;
        }
        return a[top];
    }
    bool isempty()
    {
        return (top == -1);
    }
    int size()
    {
        return top + 1;
    }
};

int evaluate_postfix(string s)
{
    stack<int> k;
    for (int i = 0; i < s.length(); i++)
    {
        char c;
        c = s[i];
        if (s[i] >= '0' && s[i] <= '9')
        {
            k.push(s[i] - 48);
            continue;
        }
        else
        {
            int g, h;
            g = k.top();
            k.pop();
            h = k.top();
            k.pop();
            switch (c)
            {
            case '*':
                k.push(h * g);
                break;
            case '/':
                k.push(h / g);
                break;
            case '+':
                k.push(h + g);
                break;
            case '-':
                k.push(h - g);
                break;
            case '^':
                k.push(h ^ g);
                break;
            }
        }
    }
    return k.top();
}

int main()
{
    // string s;
    // cin>>s;
    cout << "omkay" << endl;
    cout << evaluate_postfix("2536+**5/2-") << endl;
    // 823*+7/1–
    // 2536+**5/2-
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class poly
{
public:
    int coeff;
    int pow;
    poly *next;
    poly()
    {
        coeff = 0;
        pow = 0;
        next = NULL;
    }
    poly(int a, int b)
    {
        coeff = a;
        pow = b;
        next = NULL;
    }
};
void insert(int x, int y, poly **head)
{
    poly *element = new poly(x, y);
    element->next = *head;
    *head = element;
}
void display(poly **head)
{
    poly *temp = *head;
    while (temp != NULL)
    {
        /* code */
        cout << temp->coeff << " " << temp->pow << " " << endl;
        temp = temp->next;
    }
}

void add(poly **p1, poly **p2, poly **p3)
{
    poly *temp1 = *p1;
    poly *temp2 = *p2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->pow == temp2->pow)
        {
            insert(temp1->coeff + temp2->coeff, temp1->pow, &(*p3));
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->pow > temp2->pow)
        {
            insert(temp1->coeff, temp1->pow, &(*p3));
            temp1 = temp1->next;
        }
        else if (temp1->pow < temp2->pow)
        {
            insert(temp2->coeff, temp2->pow, &(*p3));
            temp2 = temp2->next;
        }
    }
}
int main()
{

    poly *p1 = NULL;
    insert(4, 0, &p1);
    insert(3, 1, &p1);
    insert(2, 2, &p1);
    insert(1, 3, &p1);

    poly *p2 = NULL;
    insert(4, 0, &p2);

    insert(2, 2, &p2);
    insert(1, 3, &p2);

    poly *p3 = NULL;
    display(&p1);
    cout << endl
         << endl;
    display(&p2);
    cout << endl
         << endl;
    add(&p1, &p2, &p3);
    display(&p3);

    return 0;
}
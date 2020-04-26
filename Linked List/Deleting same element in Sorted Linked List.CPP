#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
}*first;

void create(int A[], int n)
{
    node *t, *last;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Del_same(node *f)
{
    node *p = f;
    f = f->next;
    while(f)
    {
        if(p->data != f->data)
        {
            p = f;
            f = f->next;
        }
        else
        {
            p->next = f->next;
            delete f;
            f = p->next;
        }
    }
}

void display(node *f)
{
    cout << "Elements :" << endl;
    while(f)
    {
        cout << f->data << endl;
        f = f->next;
    }
}

int main()
{
    int a[] = {1, 1, 3, 3, 3};

    create(a, 5);
    display(first);
    Del_same(first);
    display(first);

    return 0;
}

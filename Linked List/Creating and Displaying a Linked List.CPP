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

void display(node *f)
{
    while(f)
    {
        cout << f->data << endl;
        f = f->next;
    }
}

void Radisplay(node *f)
{
    if(f)
    {
        cout << f->data;
        Radisplay(f->next);
    }
}

void Rddisplay(node *f)
{
    if(f)
    {
        Rddisplay(f->next);
        cout << f->data;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    create(a, 5);
    Rddisplay(first);

    return 0;
}

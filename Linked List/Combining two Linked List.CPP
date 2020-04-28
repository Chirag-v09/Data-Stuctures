#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
}*first, *bfirst;

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

void createb(int A[], int n)
{
    node *t, *last;
    bfirst = new node;
    bfirst->data = A[0];
    bfirst->next = NULL;
    last = bfirst;

    for(int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Combine(node *f, node *s)
{
    while(f->next)
    {
        f = f->next;
    }
    f->next = s;
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
    int a[] = {1, 2, 3, 4, 5}, b[] = {6, 7, 8, 9, 10};

    create(a, 5);
    createb(b, 5);
    display(first);
    display(bfirst);
    Combine(first, bfirst);
    cout << "After combining two Linked Lists:" << endl;
    display(first);

    return 0;
};

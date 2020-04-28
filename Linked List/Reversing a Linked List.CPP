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

void Reverse(node *f)
{
    int a[10], i = 0;
    while(f)
    {
        a[i++] = f->data;
        f = f->next;
    }
    i--;
    f = first;
    while(f)
    {
        f->data = a[i--];
        f = f->next;
    }
}

void Reverse_link(node *f)
{
    node *p, *q, *r;
    p = first;
    q = r = NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
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

void Reverse_recursive(node *q, node *p)
{
    if(p != NULL)
    {
        Reverse_recursive(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    create(a, 5);
    Reverse(first);
    Reverse_link(first);
    Reverse_recursive(NULL, first);
    cout << "After Reversing the Linked List:" << endl;
    display(first);

    return 0;
}

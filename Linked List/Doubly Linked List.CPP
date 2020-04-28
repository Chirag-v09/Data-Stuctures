#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
}*first;

void create(int a[], int n)
{
    node *t, *last;
    first = new node;
    first->data = a[0];
    first->next = first->prev = NULL;
    last = first;

    for(int i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(node *f)
{
    cout << "Elements:" << endl;
    while(f)
    {
        cout << f->data << endl;
        f = f->next;
    }
}

int length(node *f)
{
    int len = 0;
    while(f)
    {
        len++;
        f = f->next;
    }

    return len;
}

void Insert(node *f, int value, int pos)
{
    if(pos < 0 || pos > length(f))
        return;
    node *t = new node;
    t->data = value;
    t->next = NULL;
    t->prev = NULL;
    if(pos == 0)
    {
        t->next = f;
        f->prev = t;
        first = t;
    }
    else
    {
        for(int i = 0; i < pos-1; i++)
            f = f->next;
        t->next = f->next;
        t->prev = f;
        if(f->next)
            f->next->prev = t;
        f->next = t;
    }
}

int Delete(node *f, int pos)
{
    if(pos < 1 || pos > length(f))
        return -1;
    int x;
    if(pos == 1)
    {
        first = first->next;
        if(first)
            first->prev = NULL;
        x = f->data;
        delete f;

        return x;
    }
    else
    {
        for(int i = 0; i < pos-1; i++)
            f = f->next;
        f->prev->next = f->next;
        if(f->next)
            f->next->prev = f->prev;
        x = f->data;
        delete f;

        return x;
    }
}

void Reverse(node *f)
{
    node *t;
    int i;
    while(f)
    {
        cout << i++;
        t = f->next;
        f->next = f->prev;
        f->prev = t;
        f = f->prev;
        if(f != NULL && f->next == NULL)
            first = f;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    create(a, 5);
    Insert(first, 10, 0);
    Insert(first, 10, 6);
    Insert(first, 10, 3);
    cout << "Length:- " << length(first) << endl;
    display(first);
    cout << "Deleting 1 having value:- " << Delete(first, 1) << endl;
    display(first);
    Reverse(first);
    display(first);

    return 0;
}

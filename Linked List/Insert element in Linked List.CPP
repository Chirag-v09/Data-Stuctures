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

void Insert(node *f, int value, int pos)
{
    if(pos == 0)
    {
        node *t = new node;
        t->data = value;
        t->next = first;
        first = t;
    }
    else
    {
        node *t = new node;
        t->data = value;
        for(int i = 0; i < pos-1 && f->next; i++)
        {
            f = f->next;
        }
        t->next = f->next;
        f->next = t;
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
    int a[] = {1, 2, 3, 4, 5};

    create(a, 5);
    Insert(first, 0, 0);
    Insert(first, 11, 2);
    Insert(first, 10, 7);
    Insert(first, 15, 10);
    display(first);

    return 0;
}

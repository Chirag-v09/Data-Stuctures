#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
}*first, *bfirst, *third;

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

void display(node *f)
{
    cout << "Elements :" << endl;
    while(f)
    {
        cout << f->data << endl;
        f = f->next;
    }
}

void Merge(node *f, node *s)
{
    node *last;
    if(f->data < s->data)
    {
        third = last = f;
        f = f->next;
        last->next = NULL;
    }
    else
    {
        third = last = s;
        s = s->next;
        last->next = NULL;
    }
    while(f != NULL && s != NULL)
    {
        if(f->data < s->data)
        {
            last->next = f;
            last = f;
            f = f->next;
            last->next = NULL;
        }
        else
        {
            last->next = s;
            last = s;
            s = s->next;
            last->next = NULL;
        }
        if(f)
            last->next = f;
        else
            last->next = s;
    }
}

int main()
{
    int a[] = {2, 4, 6, 8, 10}, b[] = {1, 3, 5, 7, 9, 11, 12, 13, 14, 15};

    create(a, 5);
    createb(b, 10);
    display(first);
    display(bfirst);
    cout << "After Merging the Linked Lists:" << endl;
    Merge(first, bfirst);
    display(third);

    return 0;
}

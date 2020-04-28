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

int isLoop(node *f)
{
    node *p, *q;
    p = q = f;
    do{
        q = q->next;
        p = p->next;
        p = p?p->next:NULL;
    }while(p && q && p != q);
    if(p == q)
        return 1;
    else
        return 0;
}

int main()
{
    node *t1, *t2;
    int a[] = {1, 2, 3, 4, 5};

    create(a, 5);
    t1 = first->next;
    t2 = first->next->next->next->next;
    t2->next = t2;
    cout << isLoop(first);

    return 0;
}

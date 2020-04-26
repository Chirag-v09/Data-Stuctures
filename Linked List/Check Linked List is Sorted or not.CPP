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

bool is_sort(node *f)
{
    int x = INT32_MIN;
    while(f)
    {
        if(f->data < x)
            return false;
        x = f->data;
        f = f->next;
    }
    return true;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    create(a, 5);
    cout << is_sort(first);

    return 0;
}

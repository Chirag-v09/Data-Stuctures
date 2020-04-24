#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
}*first;

void create(int a[], int n)
{
    node *last, *t;
    first = new node;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int max(node *f)
{
    int max = f->data;
    while(f)
    {
        if(max < f->data)
            max = f->data;
        f = f->next;
    }
    return max;
}

int min(node *f)
{
    int min = f->data;
    while(f)
    {
        if(min > f->data)
            min = f->data;
        f = f->next;
    }
    return min;
}

int max1(node *f)
{
    int x;
    if(f == NULL)
        return INT32_MIN;
    else
    {
        x = max(f->next);
        if(x > f->data)
            return x;
        else
            return f->data;
    }
}

int max2(node *f)
{
    int x;
    if(f == NULL)
        return 0;
    x = max2(f->next);
    return x > f->data ? x : f->data;
}

int main()
{
    int A[] = {1,  2, 3, 4, 5};

    create(A, 5);
    cout << max1(first) << endl << min(first);
}

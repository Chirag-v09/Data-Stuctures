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

int sum(node *f)
{
    int sum = 0;

    while(f)
    {
        sum += f->data;
        f = f->next;
    }

    return sum;
}

int Rsum(node *f)
{
    if(f == NULL)
        return 0;
    return Rsum(f->next)+f->data;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    create(a, 5);
    cout << "Number of Nodes are :- " << Rsum(first) << endl;

    return 0;
}

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
    cout << "Elements :" << endl;
    while(f)
    {
        cout << f->data << endl;
        f = f->next;
    }
}

int Delete(node *f, int index)
{
    node *t;
    int x;
    if(index == 1)
    {
        t = first;
        first = first->next;
        x = t->data;
        delete t;
        return x;
    }
    else
    {
        for(int i = 0; i < index-1; i++)
        {
            t = f;
            f = f->next;
        }
        t->next = f->next;
        x = f->data;
        delete f;
        return x;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    create(a, 5);
    cout << "Deleting node 2 having value:- " << Delete(first, 2) << endl;
    display(first);

    return 0;
}

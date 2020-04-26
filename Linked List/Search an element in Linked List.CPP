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

node* Search(node *f, int key)
{
    while(f)
    {
        if(key == f->data)
            return f;
        f = f->next;
    }
    return NULL;
}

int Search_index(node *f, int key)
{
    int count = 1;
    while(f)
    {
        if(key == f->data)
            return count;
        f = f->next;
        count++;
    }
    return -1;
}

node* RSearch(node *f, int key)
{
    if(f == NULL)
        return NULL;
    if(key == f->data)
        return f;
    return RSearch(f->next, key);
}

node* Im_Search(node *f, int key)
{
    node *q;
    while(f != NULL)
    {
        if(key == f->data)
        {
            q->next = f->next;
            f->next = first;
            first = f;
            return f;
        }
        q = f;
        f = f->next;
    }
    return NULL;
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
    cout << Search_index(first, 3) << endl;
    cout << Im_Search(first, 3) << Im_Search(first, 2) << endl;
    display(first);

    return 0;
}

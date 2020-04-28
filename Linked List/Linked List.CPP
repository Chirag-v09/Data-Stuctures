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

int count(node *f)
{
    int count = 0;

    while(f)
    {
        count ++;
        f = f->next;
    }

    return count;
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

int max(node *f)
{
    int max = INT32_MIN; // int min = f->data;
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
    int min = INT32_MAX; // int min = f->data;
    while(f)
    {
        if(min > f->data)
            min = f->data;
        f = f->next;
    }
    return min;
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

int Delete(node *f, int index)
{
    node *t;
    int x;
    if(index < 1 || index > count(f))
        return -1;

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

void Del_same(node *f)
{
    node *p = f;
    f = f->next;
    while(f)
    {
        if(p->data != f->data)
        {
            p = f;
            f = f->next;
        }
        else
        {
            p->next = f->next;
            delete f;
            f = p->next;
        }
    }
}

void Reverse(node *f)
{
    int a[count(f)], i = 0;
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

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    create(a, 5);
    cout << "Number of Nodes are:- " << count(first) << endl;
    display(first);
    cout << "Sum of Elements:- " << sum(first) << endl;
    cout << "Maximum Element:- " << max(first) << endl;
    cout << "Minimum Element:- " << min(first) << endl;
    cout << "Element 1 is at:- " << Search(first, 1) << endl;
    Insert(first, 6, 6);
    Insert(first, 0, 0);
    cout << endl << "After adding 6 at 6th pos and 0 at 0th pos:" << endl;
    display(first);
    cout << "Deleting 1 Node having value:- " << Delete(first, 1) << endl;
    display(first);
    cout << "List is Sorted or Not:- " << is_sort(first) << endl;
    int b[] = {1, 1, 3, 3, 3};
    createb(b, 5);
    display(bfirst);
    Del_same(bfirst);
    cout << "After Deleting same elements in the sorted array :" << endl;
    display(bfirst);
    display(first);
    Reverse(first);
    cout << "After Reversing elements of Linked List:" << endl;
    display(first);

    return 0;
}

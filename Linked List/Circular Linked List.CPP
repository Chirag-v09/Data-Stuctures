#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
}*head;

void create(int a[], int n)
{
    node *t, *last;
    head = new node;
    head->data = a[0];
    head->next = head;
    last = head;

    for(int i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(node *h)
{
    cout << "Elements:" << endl;
    do{
        cout << h->data << endl;
        h = h->next;
    }while(h != head);
}

void Rdisplay(node *h)
{
    static int flag = 0;
    if(h != head || flag == 0)
    {
        flag = 1;
        cout << h->data << endl;
        h = h->next;
        Rdisplay(h);
    }
    flag = 0;
}

int length(node *h)
{
    int len;
    do{
        len++;
        h = h->next;
    }while(h != head);

    return len;
}

void Insert(node *h, int value, int pos)
{
    if(pos < 0 || pos > length(h))
        return;
    node *t;
    t = new node;
    t->data = value;
    t->next = NULL;

    if(pos == 0)
    {
        t->next = head;
        while(h->next != head)
            h = h->next;
        h->next = t;
        head = t;
    }
    else
    {
        for(int i = 0; i < pos-1; i++)
            h = h->next;
        t->next = h->next;
        h->next = t;
    }
}

int Delete(node *h, int pos)
{
    if(pos < 0 || pos > length(h))
        return -1;
    int x;
    if(pos == 1)
    {
        while(h->next != head)
            h = h->next;
        if(h == head)
        {
            x = head->data;
            delete head;
            head = NULL;
            return x;
        }
        else
        {
            h->next = head->next;
            x = head->data;
            delete head;
            head = h->next;
            return x;
        }
    }
    else
    {
        node *t;
        for(int i = 0; i < pos-2; i++)
            h = h->next;
        t = h->next;
        h->next = t->next;
        x = t->data;
        delete t;
        return x;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    create(a, 5);
    // cout << "Elements:" << endl;
    // Insert(head, 10, 0);
    // Insert(head, 10, 6);
    cout << "Deleting 10 having value:- " << Delete(head, 1) << endl;
    display(head);

    return 0;
}

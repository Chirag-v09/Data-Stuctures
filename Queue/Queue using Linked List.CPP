#include<iostream>

using namespace std;

class node
{
    int data;
    node *next;
public:
    void enqueue(int num);
    int dequeue();
    void display();
}*first = NULL, *Rear = NULL;

void node::enqueue(int num)
{
    node *t = new node;
    if(t == NULL)
    {
        cout << "Queue is FULL!" << endl;
        return ;
    }
    t->data = num;
    t->next = NULL;

    if(first == NULL)
    {
        first = Rear = t;
    }
    else
    {
        Rear->next = t;
        Rear = t;
    }
}

int node::dequeue()
{
    if(first == NULL)
    {
        return -1;
    }
    else
    {
        node *t = first;
        first = first->next;
        int x = t->data;
        delete t;
        return x;
    }
}

void node::display()
{
    if(first == NULL)
    {
        cout << "Queue is EMPTY!" << endl;
        return ;
    }
    cout << "Elements:" << endl;
    node *f = first;
    while(f)
    {
        cout << f->data << endl;
        f = f->next;
    }
}

int main()
{
    node n;

    n.enqueue(1);
    n.enqueue(2);
    n.enqueue(3);
    n.dequeue();
    n.dequeue();
    n.display();

    return 0;
}

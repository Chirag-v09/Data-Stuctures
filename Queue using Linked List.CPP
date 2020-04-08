#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
}*f, *r;

void push();
void pop();
void display();

int main()
{
    int c;
    char ch = 'y';

    f = NULL;
    r = NULL;
    while(ch != 'n')
    {
        cout << "Enter your Choice :- " << endl;
        cout << "1. Push." << endl;
        cout << "2. Pop." << endl;
        cout << "3. Display." << endl;
        cin >> c;

        switch(c)
        {
            case 1: push();
                    break;

            case 2: pop();
                    break;

            case 3: display();
                    break;

            default : cout << "You Enter an Invalid Option." << endl;
        }
        cout << "Do you want to continue(y/n)?" ;
        cin >> ch;
        cout << endl;
    }
}

void push()
{
    if(f == NULL)
    {
        node *n = new node;
        f = n;
        r = n;
        int num;
        cout << "Enter Value :- ";
        cin >> num;
        r->data = num;
        r->next = NULL;
    }
    else
    {
        node *n = new node;
        r->next = n;
        r = n;
        int num;
        cout << "Enter Value :- ";
        cin >> num;
        r->data = num;
        r->next = NULL;
    }
}

void pop()
{
    if(f == NULL)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        f = f->next;
        cout << "Done!" << endl;
    }
}

void display()
{
    if(f == NULL)
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        cout << "Elements are :" << endl;
        node *temp = f;
        while(f != NULL)
        {
            cout << f->data << endl;
            f = f->next;
        }
        f = temp;
    }
}

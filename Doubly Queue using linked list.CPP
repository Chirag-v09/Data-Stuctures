#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
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
        r->prev = NULL;
    }
    else
    {
        node *n = new node;
        r->next = n;
        n->prev = r;
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
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        f = f->next;
        if(f != NULL)
            f->prev = NULL;
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
        char ch;
        cout << "From which direction you want to traverse (f/r):- ";
        cin >> ch;
        switch(ch)
        {
            case 'f' : {
                        cout << endl << "Elements are f :" << endl;
                        node *temp = f;
                        while(f != NULL)
                        {
                            cout << f->data << endl;
                            f = f->next;
                        }
                        f = temp;
                       }
                        break;

            case 'r' : {
                        cout << endl << "Elements are r :" << endl;
                        node *temp = r;
                        while (r != NULL)
                        {
                            cout << r->data << endl;
                            r = r->prev;
                        }
                        r = temp;
                       }
                        break;
            default : cout << "You Enter a Wrong option!" << endl;
        }
    }
}

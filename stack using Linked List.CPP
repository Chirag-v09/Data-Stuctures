#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
}*top;

void push();
void pop();
void display();

int main()
{
    int c;
    char ch = 'y';

    top = NULL;
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
    if(top == NULL)
    {
        node *n = new node;
        top = n;
        int num;
        cout << "Enter Value :- ";
        cin >> num;
        n->data = num;
        n->next = NULL;
    }
    else
    {
        node *n = new node;
        n->next = top;
        top = n;
        int num;
        cout << "Enter Value :- ";
        cin >> num;
        n->data = num;
    }
}

void pop()
{
    if(top == NULL)
    {
        cout << "Stack is Empty!" << endl;
    }
    else
    {
        top = top->next;
        cout << "Done!" << endl;
    }
}

void display()
{
    if(top == NULL)
    {
        cout << "Stack is Empty!" << endl;
    }
    else
    {
        cout << "Elements are :" << endl;
        node *temp = top;
        while(top != NULL)
        {
            cout << top->data << endl;
            top = top->next;
        }
        top = temp;
    }
}

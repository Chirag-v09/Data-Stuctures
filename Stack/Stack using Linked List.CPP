#include<iostream>

using namespace std;

class Stack
{
    int data;
    Stack *next;
public:

    void push(int value);
    void pop();
    void display();
    int peek(int pos);
    int Stacktop();
    int isEmpty();
    int isFull();
}*top = NULL;

void Stack::push(int value)
{
    Stack *t = new Stack;
    if(t == NULL)
    {
        cout << "Stack is FULL!" << endl;
        return;
    }
    t->data = value;
    t->next = top;
    top = t;
}

void Stack::pop()
{
    if(top == NULL)
    {
        cout << "Stack is EMPTY!" << endl;
        return;
    }
    Stack *t = top;
    top = top->next;
    delete t;
}

void Stack::display()
{
    if(top == NULL)
    {
        cout << "Stack is EMPTY!" << endl;
        return;
    }
    cout << "Elements:" << endl;
    Stack *t = top;
    while(t)
    {
        cout << t->data << endl;
        t = t->next;
    }
}

int Stack::peek(int pos)
{
    int x = -1;
    if(top == NULL)
    {
        cout << "Stack is EMPTY!" << endl;
        return x;
    }
    Stack *t = top;
    for(int i = 0;t != NULL && i < pos-1; i++)
        t = t->next;
    if(t == NULL)
    {
        cout << "Invalid Option!" << endl;
        return x;
    }
    x = t->data;
    return x;
}

int Stack::Stacktop()
{
    if(top == NULL)
    {
        cout << "Stack is Empty!" << endl;
        return -1;
    }
    return top->data;
}

int Stack::isEmpty()
{
    if(top == NULL)
        return 1;
    return 0;
}

int Stack::isFull()
{
    Stack *t = new Stack;
    if(t == NULL)
        return 1;
    delete t;
    return 0;
}

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    cout << "After Pop an element from stack:" << endl;
    s.pop();
    s.display();
    cout << "Element in Position 1 is:- " << s.peek(1) << endl;
    cout << "Element in Position 2 is:- " << s.peek(2) << endl;
    cout << "Top Value of Stack:- " << s.Stacktop() << endl;
    cout << "Is Stack is Full:- " << s.isFull() << endl;
    cout << "Is Stack is Empty:- " << s.isEmpty() << endl;

    return 0;
}

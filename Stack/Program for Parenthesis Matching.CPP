#include<iostream>

using namespace std;

class Stack
{
    char data;
    Stack *next;
public:

    void push(char value);
    char pop();
    void display();
    int peek(int pos);
    int Stacktop();
    int isEmpty();
    int isFull();
    int isBalanced(char *exp);

}*top = NULL;

void Stack::push(char value)
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

char Stack::pop()
{
    if(top == NULL)
    {
        cout << "Stack is EMPTY!" << endl;
        return -1;
    }
    char x;
    Stack *t = top;
    top = top->next;
    x = t->data;
    delete t;
    return x;
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

int Stack::isBalanced(char *exp)
{
    for(int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')')
        {
            if(isEmpty())
                return 0;
            pop();
        }
    }
    if(isEmpty())
        return 1;
    return 0;
}

int main()
{
    Stack s;
    char *exp = "((a+b)*(c-d))";

    cout << s.isBalanced(exp);

    return 0;
}

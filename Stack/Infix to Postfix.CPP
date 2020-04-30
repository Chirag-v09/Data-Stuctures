#include<iostream>
#include<cstring>

using namespace std;


class Stack
{
    char data;
    Stack *next;
public:

    void push(char value);
    char pop();
    void display();
    char Stacktop();
    int isEmpty();
    int isFull();
    int isOperand(char x);
    int pre(char x);
    char* convert(char *infix);
    char* convert2(char *infix);

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

char Stack::Stacktop()
{
    if(top == NULL)
    {
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

int Stack::isOperand(char x)
{
    if(x == '*' || x == '/' || x == '+' || x == '-')
        return 0;
    return 1;
}

int Stack::pre(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

char* Stack::convert(char *infix)
{
    char *postfix = new char[strlen(infix)+1];
    int i = 0, j = 0;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(pre(infix[i]) > pre(Stacktop()))
               push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while(!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    return postfix;
}

char* Stack::convert2(char *infix)
{
    char *postfix = new char[strlen(infix)+1];
    int i = 0, j = 0;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(pre(infix[i]) > pre(Stacktop()))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while(!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    Stack s;
    char *infix = "a+b*c-d/e";

    cout << "Postfix:- " << s.convert2(infix);

    return 0;
}

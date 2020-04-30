#include<iostream>
#include<cstring>

using namespace std;


class Stack
{
    char data;
    Stack *next;
public:

    void push(int value);
    int pop();
    void display();
    int Stacktop();
    int isEmpty();
    int isFull();
    int isOperand(char x);
    int evaluation(char *postfix);

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

int Stack::pop()
{
    if(top == NULL)
    {
        cout << "Stack is EMPTY!" << endl;
        return -1;
    }
    int x;
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

int Stack::Stacktop()
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

int Stack::evaluation(char *postfix)
{
    int x1, x2, r;
    for(int i = 0; postfix[i] != '\0'; i++)
    {
        if(isOperand(postfix[i]))
            push(postfix[i] - '0');
        else
        {
            x2 = pop();
            x1 = pop();
            switch(postfix[i])
            {
                case '+' : r = x1 + x2;
                           push(r);
                           break;
                case '-' : r = x1 - x2;
                           push(r);
                           break;
                case '*' : r = x1 * x2;
                           push(r);
                           break;
                case '/' : r = x1 / x2;
                           push(r);
                           break;
            }
        }
    }
    return pop();
}

int main()
{
    Stack s;
    char *postfix = "35*62/+4-";

    cout << s.evaluation(postfix);

    return 0;
}

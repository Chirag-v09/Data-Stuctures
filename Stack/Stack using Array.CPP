#include<iostream>

using namespace std;

class Stack
{
    int size;
    int top;
    int *A;
public:
    Stack(int n)
    {
        top = -1;
        size = n;
        A = new int[n];
    }
    void push(int value)
    {
        if(top == size-1)
        {
            cout << "Stack is FULL!" << endl;
            return;
        }
        A[++top] = value;
    }
    int pop()
    {
        int x = -1;
        if(top == -1)
        {
            cout << "Stack is EMPTY!" << endl;
            return x;
        }
        x = A[top--];
        return x;
    }
    void display()
    {
        if(top == -1)
        {
            cout << "Stack is EMPTY!" << endl;
            return;
        }
        cout << "Elements:" << endl;
        for(int i = top; i >= 0; i--)
            cout << A[i] << endl;
    }
    int peek(int pos)
    {
        int x = -1;
        if(top-pos+1 < 0)
        {
            cout << "Invalid Position!" << endl;
            return x;
        }
        x = A[top-pos+1];
        return x;
    }
    int stacktop()
    {
        int x = -1;
        if(top == -1)
        {
            cout << "Stack is EMPTY!";
            return x;
        }
        x = A[top];
        return x;
    }
    int isEmpty()
    {
        if(top == -1)
            return 1;
        return 0;
    }
    int isFull()
    {
        if(top == size-1)
            return 1;
        return 0;
    }
};

int main()
{
    Stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    cout << "After Pop an element from stack:" << endl;
    s.pop();
    s.display();
    cout << "Element in Position 1 is:- " << s.peek(1) << endl;
    cout << "Element in Position 3 is:- " << s.peek(3) << endl;
    cout << "Top Value of Stack:- " << s.stacktop() << endl;
    cout << "Is Stack is Full:- " << s.isFull() << endl;
    cout << "Is Stack is Empty:- " << s.isEmpty() << endl;

    return 0;
}

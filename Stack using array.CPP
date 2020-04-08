#include<iostream>

using namespace std;

void push(int arr[10], int &top);
void pop(int &top);
void display(int arr[10], int top);

int main()
{
    int arr[10], top = -1, c;
    char ch = 'y';

    while(ch != 'n')
    {
        cout << "Enter your Choice :- " << endl;
        cout << "1. Push." << endl;
        cout << "2. Pop." << endl;
        cout << "3. Display." << endl;
        cin >> c;

        switch(c)
        {
            case 1: push(arr, top);
                    break;

            case 2: pop(top);
                    break;

            case 3: display(arr, top);
                    break;

            default : cout << "You Enter an Invalid Option.";
        }
        cout << "Do you want to continue(y/n)?" ;
        cin >> ch;
        cout << endl;
    }
}

void push(int arr[10], int &top)
{
    if(top == 9)
    {
        cout << "Stack is FULL!" << endl;
    }
    else
    {
        int num;
        top++;
        cout << "Enter a Number :- ";
        cin >> num;
        arr[top] = num;
    }
}

void pop(int &top)
{
    if(top == -1)
    {
        cout << "Stack is Empty!" << endl;
    }
    else
    {
        cout << "Done.";
        top--;
    }
}

void display(int arr[10], int top)
{
    if(top == -1)
    {
        cout << "Stack is Empty!" << endl;
    }
    else
    {
        cout << "Elements in array are :" << endl;
        for(int i = 0; i <= top; i++)
        {
            cout << arr[i] << endl;
        }
    }
}

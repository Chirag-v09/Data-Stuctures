#include<iostream>

using namespace std;

void push(int arr[10], int &f, int &r);
void pop(int &f, int &r);
void display(int arr[10], int f, int r);

int main()
{
    int arr[10], f = -1, r = -1, c;
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
            case 1: push(arr, f, r);
                    break;

            case 2: pop(f, r);
                    break;

            case 3: display(arr, f, r);
                    break;

            default : cout << "You Enter an Invalid Option.";
        }
        cout << "Do you want to continue(y/n)?" ;
        cin >> ch;
        cout << endl;
    }
}

void push(int arr[10], int &f, int &r)
{
    if(r == 9)
    {
        cout << "Can't Enter New value in Queue!" << endl;
    }
    else
    {
        if (f == -1)
        {
            int num;
            cout << "Enter Value :- ";
            cin >> num;
            f++;
            r++;
            arr[r] = num;
        }
        else
        {
            int num;
            cout << "Enter Value :- ";
            cin >> num;
            r++;
            arr[r] = num;
        }
    }
}

void pop(int &f, int &r)
{
    if ((f == -1 && r == -1) || (f > r))
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Done." << endl;
        f++;
    }
}

void display(int arr[10], int f, int r)
{
    if ((f == -1 && r == -1) || (f > r))
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        for(int i = f; i <= r; i++)
            cout << arr[i] << endl;
    }
}

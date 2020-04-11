#include<iostream>

using namespace std;

int main()
{
    int *a = new int[5];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;

    for(int i = 0; i < 5; i++)
    {
        cout << endl << a[i];
    }

    int *p = new int[10];

    for(int i = 0; i < 5; i++)
    {
        p[i] = a[i];
    }
    a = p;
    p = NULL;

    a[5] = 5;
    a[6] = 6;
    a[7] = 7;
    a[8] = 8;
    a[9] = 9;

    cout << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << endl << a[i];
    }

    cout << endl;
}

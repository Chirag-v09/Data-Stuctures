#include<iostream>

using namespace std;

int main()
{
    int a[10], *p = new int[10];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;
    p[0] = 10;
    p[1] = 20;
    p[2] = 30;
    p[3] = 40;
    p[4] = 50;
    for(int i = 0; i < 5; i++)
    {
        cout << endl << a[i] << " - " << p[i] << endl;
    }
    delete []p;
    return 0;
}

#include<iostream>

using namespace std;

int fun1(int a)
{
    static int x = 0;
    if(a > 0)
    {
        x++;
        return fun1(a - 1) + x;
    }
    return 0;
}

int i = 0;
int fun2(int a)
{
    if (a > 0)
    {
        i++;
        return fun2(a - 1) + i;
    }
    return 0;
}

int main()
{
    int a = 5;
    cout << fun1(a);
    cout << endl;
    cout << fun1(a);
    cout << endl;
    cout << fun2(a);
    cout << endl;
    cout << fun2(a);
}

#include<iostream>

using namespace std;

void fun1(int a)
{
    if(a > 0)
    {
        cout << a;
        fun1(a-1);
    }
}

void fun2(int a)
{
    if(a > 0)
    {
        fun2(a-1);
        cout << a;
    }
}

int main()
{
    int a = 3;
    fun1(a);
    cout << endl;
    fun2(a);
}

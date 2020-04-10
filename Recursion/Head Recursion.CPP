#include<iostream>

using namespace std;

void fun(int a)
{
    if(a > 0)
    {
        fun(a - 1);
        cout << a;
    }
}

int main()
{
    int a = 5;
    fun(a);
}

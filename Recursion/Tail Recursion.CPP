#include<iostream>

using namespace std;

void fun(int a)
{
    if(a > 0)
    {
        cout << a;
        fun(a - 1); // At the end line of function we are calling the recursive call hence it is a tail function
    }
}

int main()
{
    int a = 5;
    fun(a);
}

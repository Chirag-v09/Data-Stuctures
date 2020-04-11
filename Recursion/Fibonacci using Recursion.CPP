#include<iostream>

using namespace std;

int fib(int n)
{
    if(n <= 1)
        return n;
    return fib(n-2)+fib(n-1);
}

int f[10];

int mfib(int n)
{
    if(n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if(f[n-1] == -1)
            f[n-1] = mfib(n-1);
        if(f[n-2] == -1)
            f[n-2] = mfib(n-2);

        return f[n-1] + f[n-2];
    }
}

int main()
{
    for(int i=0; i < 10; i++)
        f[i] = -1;
    cout << mfib(5);
    cout << endl;
    cout << fib(6);
}

#include<iostream>

using namespace std;

int pow(int m, int n)
{
    if (n <= 1)
        return m;
    return pow(m, n-1) * m;
}

int pow1(int m, int n)
{
    if(n == 0)
        return 1;
    if(n%2 == 0)
        return pow1(m*m, n/2);
    return m*pow1(m*m, (n-1)/2);
}

int main()
{
    cout << pow1(3, 3);
    return 0;
}

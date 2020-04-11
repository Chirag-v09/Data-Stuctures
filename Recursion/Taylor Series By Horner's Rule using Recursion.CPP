#include<iostream>
#include<iomanip>

using namespace std;

double e(double x, double n)
{
    static double s = 1;
    if(n == 0)
        return s;
    s = 1 + (x/n)*s;
    return e(x, n-1);
}

int main()
{
    cout << fixed << setprecision(3) << e(1, 10);
}

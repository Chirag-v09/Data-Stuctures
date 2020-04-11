#include<iostream>

using namespace std;

int NCR(int n, int r)
{
    if(n == r || r == 0)
        return 1;
    return NCR(n-1, r) + NCR(n-1, r-1);
}

int main()
{
    cout << NCR(5, 2);
}

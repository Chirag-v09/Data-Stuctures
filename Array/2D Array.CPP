#include<iostream>

using namespace std;

int main()
{
    int ar[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int *p[3];
    p[1] = new int[3];
    p[2] = new int[3];
    p[3] = new int[3];

    int **q;
    q = new int*[3];
    q[1] = new int[3];
    q[2] = new int[3];
    q[3] = new int[3];
}

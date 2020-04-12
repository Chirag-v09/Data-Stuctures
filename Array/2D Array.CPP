#include<iostream>

using namespace std;

int main()
{
    int ar[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int *p[3];
    p[0] = new int[3];
    p[1] = new int[3];
    p[2] = new int[3];

    p[0][0] = 1;
    p[0][1] = 2;

    cout << p[0][0] << endl << p[0][1] << endl;

    int **q;
    q = new int*[3];
    q[1] = new int[3];
    q[2] = new int[3];
    q[3] = new int[3];

    q[0][0] = 10;
    q[0][1] = 20;

    cout << q[0][0] << endl << q[0][1] << endl;

}

#include<iostream>

using namespace std;

struct matrix
{
    int A[10];
    int n;
};

void set(matrix *m, int i, int j, int x)
{
    if(i == j)
        m->A[i-1] = x;
}

int get(matrix m, int i, int j)
{
    if(i == j)
        return m.A[i-1];
    return 0;
}

void display(matrix m)
{
    for(int i = 0; i < m.n; i++)
    {
        for(int j = 0; j < m.n; j++)
        {
            if(i == j)
                cout << m.A[i];
            else
                cout << "0";
        }
        cout << endl;
    }
}

int main()
{
    matrix m;
    m.n = 3;
    int i, j;

    set(&m, 1, 1, 1);
    set(&m, 2, 2, 2);
    set(&m, 3, 3, 3);
    i = 1;
    j = 1;
    cout << "Value at i = " << i << " and j = " << j << " is :- " << get(m, i, j) << endl;
    display(m);

    return 0;
}

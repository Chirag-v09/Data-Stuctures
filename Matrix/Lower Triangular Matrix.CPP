#include<iostream>

using namespace std;

// Row Major Matrix.
class MatrixR
{
    int *A;
    int n;
public:
    MatrixR(int n)
    {
        this->n = n;
        A = new int[(n*(n+1))/2];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~MatrixR()
    {
        delete A;
    }
};

void MatrixR::set(int i, int j, int x)
{
    if(i >= j)
        A[(i*(i-1))/2 +(j-1)] = x;
}

int MatrixR::get(int i, int j)
{
    if(i < j)
        return A[(i*(i-1))/2+(j-1)];
    return 0;
}

void MatrixR::display()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >= j)
                cout << A[(i*(i-1))/2+(j-1)] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

class MatrixC
{
    int *A;
    int n;
public:
    MatrixC(int n)
    {
        this->n = n;
        A = new int[(n*(n+1))/2];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~MatrixC()
    {
        delete A;
    }
};

void MatrixC::set(int i, int j, int x)
{
    if(i >= j)
        A[n*(j-1)-(j-2*(j-2] = x;
}

int MatrixC::get(int i, int j)
{
    if(i < j)
        return A[(i*(i-1))/2+(j-1)];
    return 0;
}

void MatrixC::display()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >= j)
                cout << A[(i*(i-1))/2+(j-1)] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    MatrixC m(3);
    m.set(1, 1, 1);
    m.set(2, 2, 2);
    m.set(3, 3, 3);

    cout << m.get(1, 1) << endl << m.get(1, 2) << endl;

    m.display();
}

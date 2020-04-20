#include<iostream>

using namespace std;

class Matrix
{
    int *A;
    int n;
public:
    Matrix(int n)
    {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~Matrix()
    {
        delete A;
    }
};

void Matrix::set(int i, int j, int x)
{
    if(i == j)
        A[i-1] = x;
}

int Matrix::get(int i, int j)
{
    if(i == j)
        return A[i-1];
    return 0;
}

void Matrix::display()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                cout << A[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
int main()
{
    Matrix m(3);
    m.set(1, 1, 1);
    m.set(2, 2, 2);
    m.set(3, 3, 3);

    cout << m.get(1, 1) << endl << m.get(1, 2) << endl;

    m.display();
}

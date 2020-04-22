#include<iostream>

using namespace std;

class element
{
public:
    int i;
    int j;
    int x;
};

class sparse
{
    int m;
    int n;
    int num;
    element *e;
public:
    sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        e = new element[num];
    }
    void read()
    {
        cout << "Enter Elements : " << endl;
        for(int i = 0; i < num; i++)
            cin >> e[i].i >> e[i].j >> e[i].x;
    }
    void display()
    {
        int i, j, k = 0;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(e[k].i == i && e[k].j == j)
                    cout << e[k++].x << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main()
{
    sparse s(5, 5, 5);

    s.read();
    s.display();

    return 0;
}

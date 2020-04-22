#include<iostream>

using namespace std;

class element
{
public:
    int i; // index value row
    int j; // index value column
    int x; // value at index
};

class sparse
{
    int m; // no of column
    int n; // no of row
    int num; // no. of non-zero elements
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
        for(i = 0; i < num; i++)
        {
            for(j = 0; j < num; j++)
            {
                if(e[k].i == i && e[k].j == j)
                    cout << e[k++].x << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }

    friend istream& operator>>(istream &i, sparse &s);
    friend ostream& operator<<(ostream &o, sparse s);
    sparse operator+(sparse s);
};

istream& operator>>(istream &i, sparse &s)
{
    cout << "Enter Elements :" << endl;
    for(int i = 0; i < s.num; i++)
        cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;

    return i;
}

ostream& operator<<(ostream &o, sparse s)
{
    int i = 0, j = 0, k = 0;

    cout << "Elements in Matrix :" << endl;
    for(int i = 0; i < s.m; i++)
    {
        for(int j = 0; j < s.n; j++)
        {
            if(s.e[k].i == i && s.e[k].j == j)
                cout << s.e[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return o;
}

sparse sparse::operator+(sparse s)
{
    int i = 0, j = 0, k = 0;

    if(m != s.m || n != s.n)
        return sparse(0, 0, 0);

    sparse *sum = new sparse(m, n, num + s.num);

    while(i < num && j < s.num)
    {
        if(e[i].i < s.e[j].i)
            sum->e[k++] = e[i++];
        else if(e[i].i > s.e[j].i)
            sum->e[k++] = s.e[j++];
        else
        {
            if(e[i].j < s.e[j].j)
                sum->e[k++] = e[i++];
            else if(e[i].j > s.e[j].j)
                sum->e[k++] = s.e[j++];
            else
            {
                sum->e[k] = e[i++];
                sum->e[k++].x += s.e[j++].x;
            }
        }
    }
    for(; i < num; i++)
        sum->e[k++] = e[i++];
    for(; j < s.num; j++)
        sum->e[k++] = s.e[j++];
    sum->num = k;

    return *sum;
}

int main()
{
    sparse s1(5, 5, 5), s2(5, 5, 5);

    // s.read();
    // s.display();
    cin >> s1;
    cin >> s2;
    sparse s3 = s1+s2;
    cout << "S1 " << s1;
    cout << "S2 " << s2;
    cout << "S3 " << s3;

    return 0;
}

#include<iostream>
#include<cmath>

using namespace std;

class Term
{
public:
    int coeff;
    int exp;
};

class Poly
{
    int num; // No. of terms
    Term *t;
public:
    friend istream& operator>>(istream &ci, Poly &p);
    friend int evaluate(Poly p, int x);
    friend ostream& operator<<(ostream &o, Poly p);
    friend Poly operator+(Poly p1, Poly p2);
};

istream& operator>>(istream &ci, Poly &p)
{
    cout << "Enter No. of Terms :- ";
    cin >> p.num;

    p.t = new Term[p.num];

    for(int i = 0; i < p.num; i++)
    {
        cout << "Enter Coeff. :- ";
        cin >> p.t[i].coeff;
        cout << "Enter exp. :- ";
        cin >> p.t[i].exp;
    }
    return ci;
}

int evaluate(Poly p, int x)
{
    int sum = 0;
    for(int i = 0; i < p.num; i++)
    {
        sum += p.t[i].coeff*pow(x, p.t[i].exp);
    }
    return sum;
}

ostream& operator<<(ostream &o, Poly p)
{
    for(int i = 0; i < p.num; i++)
    {
        if(i == p.num-1)
            cout << p.t[i].coeff << "x" << p.t[i].exp;
        else
            cout << p.t[i].coeff << "x" << p.t[i].exp << "+";
    }
    return o;
}

Poly operator+(Poly p1, Poly p2)
{
    Poly p;
    p.t = new Term[p1.num + p2.num];
    int i = 0, j = 0, k = 0;
    while(i < p1.num && j < p2.num)
    {
        if(p1.t[i].exp < p2.t[j].exp)
            p.t[k++] = p2.t[j++];
        else if(p1.t[i].exp > p2.t[j].exp)
            p.t[k++] = p1.t[i++];
        else
        {
            p.t[k] = p1.t[i++];
            p.t[k++].coeff += p2.t[j++].coeff;
        }
    }
    for(; i < p1.num; i++)
        p.t[k++] = p1.t[i];
    for(; j < p2.num; j++)
        p.t[k++] = p2.t[j];
    p.num = k;
    return p;
}

int main()
{
    Poly p1, p2, p3;

    cout << endl;
    cin >> p1;
    // cout << "Polynomial Evaluation at value 5 :- " << evaluate(p1, 5) << endl;
    // create(p2);
    cin >> p2;
    p3 = p1 + p2;
    cout << p1;
    cout << endl;
    cout << p2;
    cout << endl;
    cout << p3;

    return 0;
}

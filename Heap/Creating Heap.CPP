#include<iostream>

using namespace std;

void Insert(int a[], int n)
{
    int temp, i = n;
    temp = a[i];
    while(i > 1 && temp > a[i/2])
    {
        a[i] = a[i/2];
        i = i/2;
    }
    a[i] = temp;
}

void Delete(int a[], int n)
{
    int x, i, j;
    x = a[1];
    a[1] = a[n];
    i = 1;
    j = 2*i;
    while(j < n-1)
    {
        if(a[j+1] > a[j])
            j = j+1;
        if(a[i] < a[j])
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = j;
            j = 2*i;
        }
        else
            break;
    }
    a[n] = x;
}

int main()
{
    int a[] = {0, 10, 20, 30, 25, 5, 25, 40, 50};
    int i;
    for(int i = 2; i <= 8; i++)
    {
        Insert(a, i);
    }
    Delete(a, 8);
    for(int i = 0; i <= 8; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

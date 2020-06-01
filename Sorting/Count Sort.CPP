#include<iostream>

using namespace std;

void CountSort(int a[], int n)
{
    int max = 0, i, j;
    int *c;

    for(i = 0; i < n; i++)
        if(max < a[i])
            max = a[i];

    c = new int[max+1];
    for(i = 0; i < max+1; i++)
        c[i] = 0;
    for(i = 0; i < n; i++)
        c[a[i]]++;
    i = 0;
    j = 0;
    while(i < max+1)
    {
        if(c[i] > 0)
        {
            a[j++] = i;
            c[i]--;
        }
        else
            i++;
    }
}

int main()
{
    int a[] = {3, 2, 1, 6, 5, 4, 9, 8, 0, 7, 10} , n = 11;

    CountSort(a, n);
    for(int i = 0; i < n; i++)
        cout << a[i];

    return 0;
}

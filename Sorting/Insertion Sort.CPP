#include<iostream>

using namespace std;

InsertionSort(int a[], int n)
{
    int x, j;
    for(int i = 1; i < n; i++)
    {
        j = i-1;
        x = a[i];
        while(j > -1 && a[j] > x)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

int main()
{
    int a[] = {3, 2, 1, 6, 5, 4, 0, 9, 8}, n = 10;

    InsertionSort(a, 10);
    for(int i = 1; i < n; i++)
        cout << a[i];

    return 0;
}

#include<iostream>

using namespace std;

void SelectionSort(int a[], int n)
{
    int i, j, k;
    for(i = 0; i < n-1; i++)
    {
        for(j = k = i; j < n; j++)
        {
            if(a[j] < a[k])
            {
                k = j;
            }
        }
        int temp = a[k];
        a[k] = a[i];
        a[i] = temp;
    }
}

int main()
{
    int a[] = {3, 2, 1, 7, 6, 5, 4, 0, 9, 8}, n = 10;

    SelectionSort(a, n);
    for(int i = 0; i < n; i++)
        cout << a[i];

    return 0;
}

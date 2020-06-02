#include<iostream>

using namespace std;

int Partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;

    do{
        do{i++;}while(a[i] <= pivot);
        do{j--;}while(a[j] > pivot);

        if(i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }while(i < j);

    int temp = a[j];
    a[j] = a[l];
    a[l] = temp;

    return j;
}

void QuickSort(int a[], int l, int h)
{
    int j;
    if(l < h)
    {
        j = Partition(a, l, h);
        QuickSort(a, l, j);
        QuickSort(a, j+1, h);
    }
}

int main()
{
    int a[] = {3, 2, 1, 6, 5, 4, 0, 9, 8, 7, INT_MAX}, n = 11;

    QuickSort(a, 0, 10);
    for(int i = 0; i < 10; i++)
        cout << a[i];

    return 0;
}

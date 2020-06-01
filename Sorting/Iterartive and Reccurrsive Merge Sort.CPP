#include<iostream>

using namespace std;

void Merge(int a[], int l, int mid, int h)
{
    int i = l, j = mid+1, k = l;
    int b[100];

    while(i <= mid && j <= h)
    {
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    for(; i <= mid; i++)
        b[k++] = a[i];
    for(; j <= h; j++)
        b[k++] = a[j];
    for(i = 0; i <= h; i++)
        a[i] = b[i];
}

void IMergeSort(int a[], int n)
{
    int p, l, h, mid, i;
    for(p = 2; p <= n; p = p*2)
    {
        for(i = 0; i+p-1 < n; i = i+p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(a, l, mid, h);
        }
    }
    if(p/2 < n)
        Merge(a, 0, p/2-1, n-1);
}

void RMergeSort(int a[], int l, int h)
{
    if(l < h)
    {
        int mid = (l+h)/2;
        RMergeSort(a, l, mid);
        RMergeSort(a, mid+1, h);
        Merge(a, l , mid, h);
    }
}

int main()
{
    int a[] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9}, n = 10;

    // IMergeSort(a, n);
    RMergeSort(a, 0, 9);
    for(int i = 0; i < n; i++)
        cout << a[i];

    return 0;
}

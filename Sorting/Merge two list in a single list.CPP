#include<iostream>

using namespace std;

void Merge(int a[], int l, int mid, int h)
{
    int i = l, j = mid+1, k = l;
    int b[h+1];

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

int main()
{
    int a[] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9}, n = 10;

    Merge(a, 0, 4, 9);
    for(int i = 0; i < n; i++)
        cout << a[i];

    return 0;
}

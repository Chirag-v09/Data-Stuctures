#include<iostream>

using namespace std;

void Bubble(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {1, 4, 3, 2, 6, 7, 5, 9, 8, 0}, n = 10;

    Bubble(a, 10);
    for(int i = 0; i < 10; i++)
        cout << a[i];

    return 0;
}

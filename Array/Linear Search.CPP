#include<iostream>

using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Linear_Search(Array arr,int key)
{
    for(int i = 0; i < arr.length; i++)
    {
        if(key == arr.A[i])
            return i;
    }
    return -1;
}

int Improved_Linear_Search1(Array *arr, int key)
{
    for(int i = 0; i < arr->length; i++)
    {
        if(key == arr->A[i])
        {
            swap(arr->A[i], arr->A[i-1]);
            return i-1;
        }
    }
    return -1;
}

int Improved_Linear_Search2(Array *arr, int key)
{
    for(int i = 0; i < arr->length; i++)
    {
        if(key == arr->A[i])
        {
            swap(arr->A[i], arr->A[0]);
            return 0;
        }
    }
    return -1;
}

void display(Array arr)
{
    cout << endl << "Elements :" << endl;
    for(int i = 0; i < arr.length; i++)
        cout << arr.A[i] << endl;
}

int main()
{
    Array arr = {{1, 2, 3, 4, 5}, 10, 5};
    cout << Improved_Linear_Search1(&arr, 3);
    display(arr);
}

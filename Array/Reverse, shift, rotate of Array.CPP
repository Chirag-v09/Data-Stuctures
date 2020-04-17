#include<iostream>

using namespace std;

struct Array
{
    int arr[10];
    int size;
    int length;
};

// Reverse by taking new array
void NReverse(Array &arr)
{
    int b[arr.length];
    int i, j;
    for(i = arr.length-1, j = 0; i >= 0; i--, j++)
    {
        b[j] = arr.arr[i];
    }
    for(i = 0; i < arr.length; i++)
    {
        arr.arr[i] = b[i];
    }
}

// Reverse by swap elements of an array
void SReverse(Array &arr)
{
    int l = 0, h = arr.length - 1;

    while(l < h)
    {
        int temp;
        temp = arr.arr[l];
        arr.arr[l] = arr.arr[h];
        arr.arr[h] = temp;
        l++;
        h--;
    }
}

void RRotate(Array &arr)
{
    int temp;
    temp = arr.arr[arr.length-1];
    for(int i = arr.length-1; i > 0; i--)
    {
        arr.arr[i] = arr.arr[i-1];
    }
    arr.arr[0] = temp;
}

void LRotate(Array &arr)
{
    int temp;
    temp = arr.arr[0];
    for(int i = 0; i < arr.length-1; i++)
    {
        arr.arr[i] = arr.arr[i+1];
    }
    arr.arr[arr.length-1] = temp;
}

void RShift(Array &arr)
{
    for(int i = arr.length-1; i > 0; i--)
    {
        arr.arr[i] = arr.arr[i-1];
    }
    arr.arr[0] = 0;
}

void LShift(Array &arr)
{
    for(int i = 0; i < arr.length-1; i++)
    {
        arr.arr[i] = arr.arr[i+1];
    }
    arr.arr[arr.length-1] = 0;
}

void display(Array arr)
{
    for(int i = 0; i < arr.length; i++)
    {
        cout << arr.arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Array arr = {{1, 2, 3, 4, 5}, 10, 5};
    cout << "Array : ";
    display(arr);
    cout << "Reversing : ";
    NReverse(arr);
    display(arr);
    cout << "Reversing : ";
    SReverse(arr);
    display(arr);
    cout << "Right Rotate : ";
    RRotate(arr);
    display(arr);
    cout << "Left Rotate : ";
    LRotate(arr);
    display(arr);
    cout << "Right Shift : ";
    RShift(arr);
    display(arr);
    cout << "Left Shift : ";
    LShift(arr);
    display(arr);
    return 0;
}

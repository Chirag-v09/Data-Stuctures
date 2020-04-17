#include<iostream>

using namespace std;

struct Array
{
    int arr[10];
    int size;
    int length;
};

void Merge(Array arr1, Array arr2, Array &arr3)
{
    int i = 0, j = 0, k = 0;
    while(i < arr1.length && j < arr2.length)
    {
        if(arr1.arr[i] < arr2.arr[j])
        {
            arr3.arr[k] = arr1.arr[i];
            arr3.length++;
            k++;
            i++;
        }
        else
        {
            arr3.arr[k] = arr2.arr[j];
            arr3.length++;
            k++;
            j++;
        }
    }

    for(; i < arr1.length; i++)
    {
        arr3.arr[k] = arr1.arr[i];
        arr3.length++;
        k++;
    }
    for(; j < arr2.length; j++)
    {
        arr3.arr[k] = arr2.arr[j];
        arr3.length++;
        k++;
    }
}

void display(Array arr)
{
    cout << endl;
    cout << arr.length << endl;
    for(int i =0; i < arr.length; i++)
        cout << arr.arr[i] << " ";
    cout << endl;
}

int main()
{
    Array arr1 = {{0, 1, 5, 8, 9}, 10, 5};
    Array arr2 = {{2, 3, 5, 6, 7}, 10, 5};
    Array arr3;
    arr3.size = 10;
    Merge(arr1, arr2, arr3);
    display(arr3);
    return 0;
}

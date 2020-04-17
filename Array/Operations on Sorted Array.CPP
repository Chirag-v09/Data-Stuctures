#include<iostream>

using namespace std;

struct Array
{
    int arr[10];
    int size;
    int length;
};

void Insert(Array &arr, int value)
{
    int i = arr.length-1;
    while(value < arr.arr[i])
    {
        arr.arr[i+1] = arr.arr[i];
        i--;
    }
    arr.arr[i+1] = value;
    arr.length++;
}

int isSorted(Array arr)
{
    for(int i = 0; i < arr.length-1; i++)
    {
        if(arr.arr[i] > arr.arr[i+1])
            return false;
    }
    return true;
}

void Rearrange(Array &arr)
{
    int i = 0, j = arr.length-1;
    while(i < j)
    {
        while(arr.arr[i] < 0)
            {i++;}
        while(arr.arr[j] > 0)
            {j--;}
        // cout << arr.arr[i];
        // cout << arr.arr[j];
        //if(i < j)
        {
            int temp;
            temp = arr.arr[i];
            arr.arr[i] = arr.arr[j];
            arr.arr[j] = temp;
        }
    }
}

void display(Array arr)
{
    for(int i = 0; i < arr.length; i++)
    {
        cout << arr.arr[i] << " ";
    }
}

int main()
{
    Array arr = {{10, 20, 30, 40, 50}, 10, 5};
    Insert(arr, 25);
    display(arr);
    cout << endl << "Array is ";
    isSorted(arr)?cout << "Sorted" : cout << "Unsorted";
    cout << endl;
    Array arr1 = {{-100, 20, -30, 25, -10}, 10, 5};
    Rearrange(arr1);
    cout << "Rearrange : ";
    display(arr1);
    return 0;
}

#include<iostream>

using namespace std;

struct Array
{
    int arr[10];
    int size = 10;
    int length = 0;
};

void Union(Array arr1, Array arr2, Array &arr3)
{
    for(int i = 0; i < arr1.length; i++)
    {
        arr3.arr[i] = arr1.arr[i];
        arr3.length++;
    }
    for(int i = 0; i < arr2.length; i++)
    {
        int flag = 0;
        for(int j = 0; j < arr1.length; j++)
        {
            if (arr2.arr[i] == arr1.arr[j])
                flag = 1;
        }
        if(flag == 1)
            continue;
        arr3.arr[arr3.length++] = arr2.arr[i];
    }
}

void Union_Sort(Array arr1, Array arr2, Array &arr3)
{
    int i = 0, j = 0, k = 0;
    while(i < arr1.length && j < arr2.length)
    {
        if(arr1.arr[i] == arr2.arr[j])
        {
            arr3.arr[k] = arr1.arr[i];
            i++;
            j++;
            k++;
            arr3.length++;
        }
        else if(arr1.arr[i] < arr2.arr[j])
        {
            arr3.arr[k] = arr1.arr[i];
            i++;
            k++;
            arr3.length++;
        }
        else
        {
            arr3.arr[k] = arr2.arr[j];
            j++;
            k++;
            arr3.length++;
        }
    }
    for(; i < arr1.length; i++)
    {
        arr3.arr[k] = arr1.arr[i];
        k++;
        arr3.length++;
    }
    for(; j < arr1.length; j++)
    {
        arr3.arr[k] = arr2.arr[j];
        k++;
        arr3.length++;
    }
}

void Intersection(Array arr1, Array arr2, Array &arr3)
{
    for(int i = 0; i < arr1.length; i++)
    {
        int flag = 0;
        for(int j = 0; j < arr2.length; j++)
        {
            if(arr1.arr[i] == arr2.arr[j])
                flag = 1;
        }
        if(flag == 1)
        {
            arr3.arr[arr3.length++] = arr1.arr[i];
        }
    }
}

void Intersection_Sort(Array arr1, Array arr2, Array &arr3)
{
    int i = 0, j = 0, k = 0;
    while(i < arr1.length && j < arr2.length)
    {
        if(arr1.arr[i] == arr2.arr[j])
        {
            arr3.arr[k] = arr1.arr[i];
            arr3.length++;
            k++;
            i++;
            j++;
        }
        else if(arr1.arr[i] < arr2.arr[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}

void Difference(Array arr1, Array arr2, Array &arr3)
{
    for(int i = 0; i < arr1.length; i++)
    {
        int flag = 0;
        for(int j = 0; j < arr2.length; j++)
        {
            if(arr1.arr[i] == arr2.arr[j])
                flag = 1;
        }
        if(flag != 1)
        {
            arr3.arr[arr3.length++] = arr1.arr[i];
        }
    }
}

void Difference_Sort(Array arr1, Array arr2, Array &arr3)
{
    int i = 0, j = 0, k = 0;
    while(i < arr1.length && j < arr2.length)
    {
        if(arr1.arr[i] < arr2.arr[j])
        {
            arr3.arr[k] = arr1.arr[i];
            k++;
            i++;
            arr3.length++;
        }
        else if(arr1.arr[i] > arr2.arr[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
            // cout << i << endl;
        }
    }
    for(; i < arr1.length; i++)
        arr3.arr[arr3.length++] = arr1.arr[i];
}

void display(Array arr)
{
    cout << endl << arr.length << endl;
    for(int i = 0; i < arr.length; i++)
    {
        cout << arr.arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Array arr1 = {{1, 5, 3, 2, 4}, 10, 5};
    Array arr2 = {{8, 7, 3, 4, 0}, 10, 5};
    Array arr3;
    Array arr4 = {{1, 2, 3, 4, 5}, 10, 5};
    Array arr5 = {{1, 2, 4, 6, 9}, 10, 5};
    Array arr6;
    Array arr7;
    Array arr8;
    Array arr9;
    Array arr10;

    Union(arr1, arr2, arr3);
    display(arr3);

    Union_Sort(arr4, arr5, arr6);
    display(arr6);

    Intersection(arr1, arr2, arr7);
    display(arr7);

    Intersection_Sort(arr4, arr5, arr8);
    display(arr8);

    Difference(arr1, arr2, arr9);
    display(arr9);

    // cout << "hello" << endl;

    Difference_Sort(arr4, arr5, arr10);
    display(arr10);

    return 0;
}

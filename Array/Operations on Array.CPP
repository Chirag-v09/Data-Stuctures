#include<iostream>

using namespace std;

struct Array
{
    int arr[10];
    int size;
    int length;
};

int Get(Array arr, int index)
{

    if(index >= 0 && index < arr.length)
        return arr.arr[index];
    return -1;
}

void Set(Array &arr, int value, int index)
{
    if(index >= 0 && index < arr.length)
        arr.arr[index] = value;
    else
        cout<< "You Enter Wrong Option :";
}

int Max(Array arr)
{
    int max = arr.arr[0];
    for(int i = 1; i < arr.length; i++)
    {
        if(max < arr.arr[i])
            max = arr.arr[i];
    }
    return max;
}

int Min(Array arr)
{
    int min = arr.arr[0];
    for(int i = 1; i < arr.length; i++)
    {
        if(min > arr.arr[i])
            min = arr.arr[i];
    }
    return min;
}

int Sum(Array arr)
{
    int sum = 0;
    for(int i = 0; i < arr.length; i++)
        sum += arr.arr[i];
    return sum;
}

int Avg(Array arr)
{
    int sum = 0;
    for(int i = 0; i < arr.length; i++)
        sum += arr.arr[i];
    return sum / arr.length;
}

int main()
{
    Array arr = {{1, 2, 3, 4, 5}, 10, 5};
    Set(arr, 10, 1);
    cout << endl << Get(arr, 1) << endl << Max(arr) << endl << Min(arr) << endl << Sum(arr) << endl << Avg(arr);
    return 0;
}

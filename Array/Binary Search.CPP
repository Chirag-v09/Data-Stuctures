#include<iostream>

using namespace std;

struct Array
{
    int arr[10];
    int size;
    int length;
};

int Binary_Search(Array arr, int key)
{
    int l = 0;
    int h = arr.length;

    while(l <= h)
    {
        int mid = (l+h)/2;
        if (arr.arr[mid] == key)
            return mid;
        else if (key > arr.arr[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

int RBSearch(int l, int h, int arr[], int key)
{
    if(l <= h)
    {
        int mid = (l + h) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            return RBSearch(mid+1, h, arr, key);
        else
            return RBSearch(l, mid-1, arr, key);
    }
    return -1;
}

int main()
{
    Array arr1 = {{1, 2, 3, 4, 5}, 10, 5};
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << Binary_Search(arr1, 3) << endl << RBSearch(0, 9, arr, 3);
    return 0;
}

#include<iostream>

using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;

    void display()
    {
        cout << endl;
        for(int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

void Append(Array *arr, int value)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = value;
    else
        cout << "Array is Full";
}

void Insert(Array *arr, int index, int value)
{
    if(index <= arr->length && index >= 0)
    {
        for(int i = arr->length; i > index; i--)
            {
                arr->A[i] = arr->A[i-1];
                // cout << arr->A[i-1];
            }
        arr->A[index] = value;
        arr->length++;
        // cout << endl << arr->length << endl;
    }
}

void Delete(Array *arr, int index)
{
    if(index >= 0 && index < arr->length)
    {
        int x = arr->A[index];
        for(int i = index; i < arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->A[arr->length - 1] = 0;
        arr->length--;
    }
}

//////////////

struct Array2
{
    int *A;
    int size;
    int length;
};

void display(Array2 arr)
{
    for(int i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
}

void Append(Array2 *arr, int value)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = value;
    else
        cout << "Array is Full";
}

void Insert(Array2 *arr, int index, int value)
{
    if(index <= arr->length && index >= 0)
    {
        for(int i = arr->length; i >index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = value;
        arr->length++;
    }
}

void Delete(Array2 *arr, int index)
{
    if(index >= 0 && index < arr->length)
    int x = arr->A[index];
    for(int i = index; i < arr->length-1; i++)
        arr->A[i] = arr->A[i+1];
    arr->length--;
}

int main()
{
    Array arr = {{1, 2, 3, 4, 5}, 10, 5};
    Insert(&arr, 2, 10);
    Append(&arr, 6);
    Delete(&arr, 0);
    arr.display();
    cout << endl;


    Array2 arr2;
    int size;
    cout << "Enter size of Array :- ";
    cin >> arr2.size;
    arr2.A = new int[arr2.size];
    // arr2.size = size;


    cout << "Enter no. of elements you want to enter :- ";
    cin >> arr2.length;

    cout << "Enter Elements :" << endl;
    for(int i = 0; i < arr2.length; i++)
    {
        cin >> arr2.A[i];
    }

    Append(&arr2, 10);
    Insert(&arr2, 2, 100);
    Delete(&arr2 ,0);
    display(arr2);
}

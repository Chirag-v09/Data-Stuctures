#include<iostream>

using namespace std;

int main()
{
    char a[10], t;
    int i, j;

    cout << "Enter a String :- ";
    cin >> a;

    cout << "Reverse of it is :- ";
    for(i = 0; a[i] != '\0'; i++);
    for(i = i-1, j = 0; i > j; i--, j++)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    cout << a << endl;
    return 0;
}

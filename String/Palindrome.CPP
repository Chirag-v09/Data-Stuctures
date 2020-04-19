#include<iostream>

using namespace std;

int check(char a[])
{
    int i, j;
    for(i = 0; a[i] != '\0'; i++);
    for(i = i-1, j = 0; i > j; i--, j++)
    {
        if(a[i] != a[j])
            return 0;
    }
    return 1;
}
int main()
{
    char a[10];

    cout << endl << "Enter String :- ";
    cin >> a;

    if(check(a))
        cout << "String is Palindrome." << endl;
    else
        cout << "String is Not Palindrome." << endl;

    return 1;
}

#include<iostream>

using namespace std;

int validate(char a[100])
{
    for(int i = 0; a[i] != '\0'; i++)
    {
        if(!(a[i] >= 65 && a[i] <= 'Z') && !(a[i] >= 97 && a[i] <= 'z') && !(a[i] >= '0' && a[i] <= '9'))
        {
            cout << "Hello";
            return 0;
        }
    }

    return 1;
}

int main()
{
    char a[100];
    cout << "Enter a String :- ";
    cin >> a;
    if(validate(a))
        cout << endl << "String is Valid." << endl;
    else
        cout << endl << "String is Not Valid." << endl;
    return 0;
}

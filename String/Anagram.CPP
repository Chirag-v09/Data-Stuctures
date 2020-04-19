#include<iostream>

using namespace std;

int main()
{
    int h[26] = {0}, flag = 0;
    char a[10], b[10];

    cout << "Enter first String :- ";
    cin >> a;
    cout << endl << "Enter second String :- ";
    cin >> b;

    for(int i = 0; a[i] != '\0'; i++)
    {
        h[int(a[i])-97] += 1;
    }
    for(int i = 0; b[i] != '\0'; i++)
    {
        h[int(b[i])-97] -= 1;
    }
    for(int i = 0; i < 26; i++)
    {
        if(h[i] != 0)
            flag = 1;
    }
    if(flag == 0)
        cout << endl << "String is Anagram." << endl;
    else
        cout << endl << "String is not Anagram." << endl;
    return 0;
}

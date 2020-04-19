#include<iostream>

using namespace std;

void duplicates(char a[10])
{
    int i, len, count;
    // for(len = 0; a[len] != '\0'; len++);
    for(i = 0; a[i] != '\0'; i++)
    {
        if(a[i] != '0')
        {
            count = 1;
            for(int j = i+1; a[j] != '\0'; j++)
            {
                if(a[i] == a[j])
                    {
                        count++;
                        a[j] = '0';
                    }
            }
            cout << a[i] << " = " << count << endl;
        }
    }
}

int main()
{
    char a[10];

    cout << "Enter String :- ";
    cin >> a;
    duplicates(a);
    // char c = 'a', d = 'a';

    return 0;
}

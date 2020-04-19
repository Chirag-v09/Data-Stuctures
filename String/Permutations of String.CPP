#include<iostream>

using namespace std;

void permu(char a[], int k)
{
    static int p[10] = {0};
    static char res[10];

    if(a[k] == '\0')
    {
        res[k] = '\0';
        cout << res << endl;
    }
    else
    {
        for(int i = 0; a[i] != '\0'; i++)
        {
            if(p[i] == 0)
            {
                res[k] = a[i];
                p[i] = 1;
                permu(a, k+1);
                p[i] = 0;
            }
        }
    }
}

int main()
{
    char a[10];

    cout << "Enter a String :- ";
    cin >> a;
    permu(a, 0);

    return 0;
}

#include<iostream>

using namespace std;

int main()
{
    char s[] = "WElcOme";

    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] >= 65 && s[i] <= 'Z')
        {
            s[i] += 32;
        }
        else if(s[i] >= 97 && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }
    cout << s;

    return 0;
}

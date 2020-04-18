#include<iostream>

using namespace std;

int main()
{
    char s[] = "welcome to computer classes";
    int i, cc = 0, cv = 0, cw = 0;

    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            cv++;
        else if(s[i] >= 97 && s[i] <= 'z')
            cc++;
        else if(s[i] == ' ' && s[i-1] != ' ')
            cw++;
    }

    cout << endl << "Vowels :- " << cv << endl << "Consonents :- " << cc << endl << "Words :- " << ++cw << endl;
    return 0;
}

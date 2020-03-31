#include <bits/stdc++.h>

using namespace std;

int main()
{
    int no_of_inputs;
    cin >> no_of_inputs;

    int a[no_of_inputs], result = 0;

    for(int i=0; i<no_of_inputs; i++)
    {
        cin>>a[i];
        result += a[i];
    }

    cout<<result;
}
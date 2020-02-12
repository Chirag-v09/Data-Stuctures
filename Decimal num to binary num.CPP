#include<iostream.h>
#include<conio.h>

void main()
{
 clrscr();
 int n, a, b, bn, j;
 cout<<"Enter number :- ";
 cin>>n;
 a = 0;
 b = n;
 bn = 0;
 j = 1;
 while(b != 1)
 {
  a = b%2;
  b = b/2;
  bn = a*j + bn;
  j = j*10;
 }
 bn = b*j + bn;
 cout<<"Binary Number is :- "<<bn;
 getch();
}
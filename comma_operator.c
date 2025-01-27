#include<stdio.h>
int main()
{
    int a=5;int b=6;int c=7;
    int y; int z;

    y=a,b,c;
    printf("value of y=%d",y);

    z=(a,b,c);
    printf("value of z=%d",z);



}
#include<stdio.h>
int breakr(int , int*);
int main()
{

    long long int n,count=0;
    scanf("%lld",&n);
    printf("%d",breakr(n,&count));
}
int breakr(int n,int * count)
{
    int x,y=0;

    if(n==1)
        return *count;
    if(n==2||n==3||n==4||n==5||n==6||n==8||n==9)
        return -1;

    while(n!=0)
    {
        x = n%10;
        y = y + x*x;
        n=n/10;
    }
    *count = *count + 1;
    return breakr(y,count);
}

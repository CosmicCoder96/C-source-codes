#include<stdio.h>
int fact(int x);
int main()
{
    int n;
    printf("Enter the number: \n");
    scanf("%d",&n);
    printf("%d",fact(n));

}
int fact(int x)
{
    if(x==0)
        return 1;
    else
        return x*fact(x-1);
}

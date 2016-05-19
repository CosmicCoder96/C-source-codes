#include<stdio.h>
int main()
{
long long int t,l,sum,n,x,avg;
scanf("%lld",&t);
while(t--)
{
    scanf("%lld %lld",&x,&avg);
    n = avg - x +1;
    sum = n*avg;
    n--;
    sum-=x;
    l = sum - n*(n-1)/2;
    printf("%lld\n",l);
}

}

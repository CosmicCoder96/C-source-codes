#include<stdio.h>
int gcd(long long int a,long long int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,i,x,count=0;

        scanf("%lld",&n);
        x = ceil((double)(n-2)/2);
     /*   for(i=1;i<=n-2;i++)
        {
           if(gcd(i,i+1)==1&&gcd(i+1,i+2)==1&&gcd(i,i+2)==1)
                count+=i;

        }*/
        printf("%lld\n",(x*x)%n);

    }
}

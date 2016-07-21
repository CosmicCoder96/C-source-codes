#include<stdio.h>
int main()
{
    int t;
    long long int a,b,c,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        ans  = a*a - 2*b;
        printf("%lld\n",ans);

    }
}

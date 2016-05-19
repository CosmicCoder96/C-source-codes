#include<stdio.h>
#include<math.h>
int main()
{
    long double A = 0.3990899341790575247825035915077;
    long double B = 0.4342944819032518276414969;
    long long int n,T;

    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        if(n==0 || n==1)    {
            printf("1\n");
        continue;
        }
        long double k=log10(n);
        long long ans = floor(A+ (double)k/2 + (double)n*(k-B))+1;
        printf("%lld\n",ans);
    }
}

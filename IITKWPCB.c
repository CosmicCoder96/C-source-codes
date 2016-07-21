#include<stdio.h>
int main()
{
    long long int t,x,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n%2!=0)
            printf("%lld\n",n/2);
        else
        {
            x = n/2;
         if(x%2==0&&n%2==0)
         {
             n=n/2;
             printf("%lld\n",n-1);

         }
         else
         {
             n=n/2;
             printf("%lld\n",n-2);
         }

        }

    }
}

#include<stdio.h>
#include<math.h>
#define mo 1000000007
int main()
{


long long int t,n,k,k2,s=0,i;
scanf("%lld",&t);
while(t--)
{
    scanf("%lld",&n);
    for(i=1;i<=sqrt(n);i++)
        {
            k = n/i;

            k2= n/(n-i);
                if(i*i==n)
                    s=(s+n)%mo;
                else
                s = (s + (k2*(n-i)+k*i))%mo;






        }
        for(i=floor(sqrt(n))+1;i<=n/2;i++)
        {
            k=n/i;
            k2= n/(n-i);
            if((n/2)*2==n)

                s = (s + (k2*(n-i)+k*i))%mo;
           printf("kabuki");
        }
        s+=n%mo ;
        printf("%lld\n",s%mo);
        s=0;
}
}

#include<stdio.h>
#include<math.h>
int fib[15]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377};
int main()
{
    long long int  t,x,n,i,m;
    scanf("%lld",&t);
    x = t;
    while(t--)
    {
        long long int s = 0,count = 0;

        scanf("%lld %lld",&n,&m);
        for(i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                s = s + i;
                if(i!=n/i)
                    s = s+n/i;
            }

        }
        if(n!=1)
    s=s-n;
     //   printf("%lld\n",s);
        s = s%m;
        for(i=1;i<=sqrt(s);i++)
        {
            if(s%i==0)
            {
                count++;
                if(i!=s/i)
                    count++;
            }
        }
        if(s>1)
        count--;
      //  printf("%lld\n",count);
        for(i=0;i<=14;i++)
        {
            if(fib[i]==count)
            {
                printf("Case #%lld : YES.\n",x-t);
                break;

            }
        }

        if(i==15)
        printf("Case #%lld : NO.\n",x-t);



    }
}


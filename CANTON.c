#include<stdio.h>
#include<math.h>
int main()
{
    long long int t,n,x,y,z,num,den;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        x = ceil((double)((-1+sqrt(1+8*n))/2));
        y = x*(x+1)/2;
        z = y-n;
        //printf("%lld",z);
        if(x%2!=0)
            {
            num = 1;
            den=x;
            while(z--)
        {
            num++;
            den--;


        }
        }
        else
        {
            den=1;
            num=x;
            while(z--)
        {
            num--;
            den++;


        }
        }

        printf("TERM %lld IS %lld/%lld\n",n,num,den);
    }
}

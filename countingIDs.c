#include<stdio.h>
#define num 1000000007
#define ll long long
ll modular_pow(ll base, ll exponent, ll modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
int main()
{
    long long int t,N,L,z,i,x=0,y;
    //scanf("%lld",&t);
    while(1<2)
        {

            scanf("%lld %lld",&N,&L);
            if(N==0&&L==0)
                break;
            if(N==1)
                x =  L;
            else
           {
                for(i=1;i<=L;i++)
                x = x + modular_pow(N,i,num);
              // y = (x-N%num)%num;
              // z =( y%num*(N-1)%num)%num;
               //printf("%d ",x);
           }

            printf("%lld\n",x%num);
            x=0;



        }
    return 0;
}

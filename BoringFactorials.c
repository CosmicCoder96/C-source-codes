#include<stdio.h>
#define ll long long
ll modfact(ll a,ll b)
{
    ll fact = 1,i=1;
    if(a>b)
        return 0;


    for(i=a+1;i<=b;i++){
    fact = ((fact%b )* (i%b))%b;
    }
    return (b-1)/fact;
}
int main()
{
    ll t,N,P,x;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&N);
        scanf("%lld",&P);
        x = modfact(N,P);
        printf("%lld\n",x);

    }
    return 0;
}

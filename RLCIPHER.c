#include<stdio.h>
long long int RL(long long int x)
{
    if(x<0)
        return x;
    if(x>6||x%4==0||x%3==0)
        return -4;

    if(x==2)
        return -2;
    if(x==5||x==1)
        return -3;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
           long long  int n,x;
            scanf("%lld",&n);
            n--;
            while(n--)
            {
                scanf("%lld",&x);
                printf("%lld ",RL(x));
            }
            scanf("%lld",&x);
            printf("%lld\n\n",RL(x));
    }
}

#include<stdio.h>
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
{   int t;
    long long int b;
    char a[1000000];
    scanf("%d",&t);
    while(t--){
        scanf("%s %lld",a,&b);
        int l = strlen(a);
        if(a[l-1]-'0'!=0)
        printf("%lld\n",modular_pow(a[l-1]-'0',b,10));
        else
            printf("0\n");

    }


}

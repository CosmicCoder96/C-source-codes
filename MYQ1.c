#include<stdio.h>
int main()
{   float x;
    long long int n, t,A;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        A = (n+3)/5;

        if(n==1)
        {
            printf("poor conductor\n");
            continue;
        }
        printf("%lld ",A);
        if((n+9)%10==0||(n+8)%10==0)
            printf("W L");
        else if((n+7)%10==0||n%10==0)
            printf("A L");
        else if((n+6)%10==0||(n+1)%10==0)
            printf("A R");
        else if((n+5)%10==0||(n+2)%10==0)
            printf("M R");
        else if((n+4)%10==0||(n+3)%10==0)
            printf("W R");
        else
            continue;


        printf("\n");




    }
}

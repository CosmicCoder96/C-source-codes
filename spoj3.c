
#include<stdio.h>

int main()
{

    float t,N,K,M,T=0;

    scanf("%f",&t);
    while(t--)
    {
        scanf("%f %f %f",&N,&K,&M);


        while(N<=M)
        {

            N*=K;
            if(N>M)
                break;
            T++;
        }
        printf("%g\n",T);
        T=0;
        }

return 0;
}


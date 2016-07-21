#include<stdio.h>
int main()
{
    // red - 0 blue - 1
    long long int y,z,p,count=0,x;
    scanf("%lld %lld",&y,&p);
    z=y;
    y--;
    long long int pval=0;
    while(p!=0)
    {
        x = pow(2,y);

        if(p-x>=0)
        {
            p = p- x;
            count++;
            z--;
        }




       // printf("%lld ",p);
        y--;

    }
    //printf("%lld",pow(2,y));
    if(z%2==0)
        printf("red");
    else
        printf("blue");



}

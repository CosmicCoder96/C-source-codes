#include<stdio.h>
long long int max(long long int a,long long int b,long long int m)
{

    return (a>b)?a:b;

}
long long int min(long long int a,long long int b,long long int m)
{

    return (a<b)?a:b;

}

int main()
{
    long long int n,m,i,j,k,sum=0,max=0,index=0;
    scanf("%lld %lld",&n,&m);
    long long int a[n];
    for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);//2 1 3 4 5


        }


    for(i=0;i<n;i++)
    {
    sum+=a[i];
    if(sum>m)
    {
        while(sum>m)
        {
            sum-=a[index++];
        }
    }
   // printf("%lld\n",sum);
    if(sum>max)
        max=sum;




    //printf("%lld\n",maxcurrent);
    }
    printf("%lld",max);
}

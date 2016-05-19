#include<stdio.h>
#include<stdlib.h>
long long int recsum(long long int n,int*);
//int flag[10000000]={0};

 //int *p = (int*)malloc(sizeof(int)*10);
int main()
{
    long long int i,n,a;
    int *flag = (int*)malloc(sizeof(int)*100000000);
    for(i=1;i<100000000;i++)
        flag[i]=0;



    while(1<2){
        scanf("%lld",&n);
    if(n==-1)
        break;

    a = recsum(n,flag);
    printf("%lld\n",a);


    }
}
long long int recsum(long long int n,int *flag)
{
     long long int sum=0;
    if(n==0)
        return 0;
    else{
        sum =  recsum(n-1,flag) - n;
        if(sum<=0||flag[sum]==1){
        sum = recsum(n-1,flag) + n;
    flag[sum]=1;}
    return sum;}
}

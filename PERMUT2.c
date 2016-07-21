#include<stdio.h>
int main()
{
    int t,k,i;

    while(1)
    {
        scanf("%d",&t);
        if(t==0)
            break;
        int a[t],b[t+1];S
        for(i=1;i<=t;i++){
            scanf("%d",&a[i]);
        b[a[i]]=i;
      //  printf("00");


    }
    int flag=0;
    for(i=1;i<=t;i++)
    {
        if(b[i]!=a[i])
            flag = 1;
    }
    if(flag==0)
        printf("ambiguous\n");
    else
        printf("not ambiguous\n");
}}


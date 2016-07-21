#include<stdio.h>
int a[1000001]={0};

int main()
{
    int i,j,k,x,t,y=0,n;
    for(i=2;i<=100;i++)
    {
        k = i*i*i;
        for(j=k;j<=1000000;j+=k)
        {
            a[j]=-1;
        }


    }
    x=1;
    for(i=1;i<1000000;i++)
    {
        if(a[i]==0)
        {
          a[i]=x++;
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        y++;
        scanf("%d",&n);


       if(a[n]==-1)
       printf("Case %d: Not Cube Free\n",y);

       else{
       printf("Case %d: %d\n",y,a[n]);

       }


    }
}

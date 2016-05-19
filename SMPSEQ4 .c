#include<stdio.h>
int main()
{

    int n,m,x,i;
    int a[1000];
    int b[1000];
    for(i=0;i<1000;i++)
        b[i]=0;
    scanf("%d",&n);
    int s[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);


    }
     scanf("%d",&m);
    int q[m];
    for(i=0;i<m;i++)
    {
        scanf("%d",&q[i]);
        x = q[i];
        if(q[i]<0)
            x=q[i]+500;
        b[x]=1;

    }
    for(i=0;i<n;i++)
    {   x = s[i];
        if(s[i]<0)
            x=s[i]+500;
        if(b[x]==1)
        printf("%d ",s[i]);
    }
}

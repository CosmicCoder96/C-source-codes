#include<stdio.h>
int main()
{
    int t,n,x,i,flag=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
            a[i]=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x<n)
            {
                if(a[x]==0)
                    a[x]=1;
                else
                    a[n-x-1]=1;
            }
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
                flag=1;
        }
        if(flag==0)
            printf("YES\n");
        else
            printf("NO\n");
        flag=0;
    }
}

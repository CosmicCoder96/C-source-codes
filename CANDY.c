#include<stdio.h>
int main()
{
int t,n,i,m,total,avg,ans;
while(1)
{
    scanf("%d",&n);

    if(n==-1)
        break;

    else
    {
        int a[n];
        total=0;
        ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            total+=a[i];
        }
        if(total%n!=0)
        {
            printf("-1\n");
        }
        else
        {
            avg=total/n;
            for(i=0;i<n;i++)
            {
                if(a[i]>avg)
                {
                    ans+=(a[i]-avg);
                }
            }
            printf("%d\n",ans);
        }

    }
}
return 0;
}

#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t,i,j,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        long long int a[n],count=0;
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        sort(a,a+n);
        for(i=0;i<n-1;i++)
        {
            if(a[i]==0)
                continue;
            for(j=i+1;j<n;j++)
            {
                if(2*a[i]==a[j]||2*a[j]==a[i])
                {
                    count ++;
           //         printf("%d %d %lld %lld\n",i,j,a[i],a[j]);

                    a[j]=0;
                    break;
                }
            }
        }
        printf("%lld\n",count);
    }


}

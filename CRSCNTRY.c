#include<stdio.h>
long long int tom[1001][1001];
long long int DP[1002][1002];
long long int nm;
long long int m[2001];
long long int max;
long long int maxE(long long int a , long long int b)
{
    return a>b?a:b;
}
long long int LCS(long long int tom[],long long int n)
{
    int i,j;
    for(i=0;i<nm;i++)
    {
        DP[0][i]=0;
    }
    for(i=0;i<n;i++)
    {
        DP[i][0]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=nm;j++)
        {
            if(tom[i-1]==m[j-1])
                DP[i][j]=DP[i-1][j-1]+1;
            else
                DP[i][j]=maxE(DP[i-1][j],DP[i][j-1]);
        }
    }
//    for(i=0;i<=n;i++)
//    {
//        for(j=0;j<=nm;j++)
//        {
//            printf("%lld ", DP[i][j]);
//        }
//        printf("\n");
//    }
    return DP[n][nm];
}
int main()
{
    long long int t,i=0,j=0,temp,x;
    scanf("%lld",&t);
    while(t--)
    {
        while(1)
        {
            scanf("%lld",&temp);
            if(temp==0)
                break;
            else
                m[i++]=temp;
        }
        nm=i;
        i=0;

        while(1)
        {
            while(1)
            {
                scanf("%lld",&temp);
                if(temp==0)
                    break;
                else
                    tom[i][j++]=temp;
            }
            if(temp==0&&j==0)
                break;
            x=LCS(tom[i],j);
            if(x>max)
                max=x;
            j=0;
            i++;
        }
        printf("%lld\n",max);
        max=0;
         i=0;
    }

}

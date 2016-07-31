#include<stdio.h>
#include<string.h>
int DP[2001][2001];
int min(int a,int b, int c)
{
    int m =a;
    if(m>b)
        m=b;
    if(m>c)
        m=c;
    return m;
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        char A[2001],B[2001];
        scanf("%s",A);
        scanf("%s",B);
        int l1 =strlen(A);
        int l2=strlen(B);
        for(i=1;i<=l1;i++)
        {
            DP[0][i]=i;
        }
        for(i=1;i<=l2;i++)
        {
            DP[i][0]=i;
        }
        for(i=1;i<=l2;i++)
        {
            for(j=1;j<=l1;j++)
            {
                if(A[j-1]!=B[i-1])
               DP[i][j]=min(DP[i][j-1],DP[i-1][j],DP[i-1][j-1]) +1;
               else
                DP[i][j]=DP[i-1][j-1];

            }
        }/*
        for(i=0;i<=l2;i++)
        {
            for(j=0;j<=l1;j++)
            {
                printf("%d ",DP[i][j]);
            }
            printf("\n");
        }*/
        printf("%d\n",DP[l2][l1]);
    }
}

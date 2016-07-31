#include<stdio.h>
int n;
int count=0;
int treat[2001];
int cache[2001][2001]={0};
int max(int a,int b)
{
    return a>b?a:b;
}
int TRT(int top, int bottom)
{
    if(top>bottom)
        return 0;
    if(cache[top][bottom]!=0)
        return cache[top][bottom];
    int val;
    if(treat[top+1]>=treat[bottom]&&treat[top]>=treat[bottom-1])
            return cache[top][bottom]=max(TRT(top+2,bottom)+treat[top],TRT(top+1,bottom-1)+treat[bottom]);

    else if(treat[top+1]>=treat[bottom]&&treat[top]<treat[bottom-1])
            return cache[top][bottom]=max(TRT(top+2,bottom)+treat[top],TRT(top,bottom-2)+treat[bottom]);
    else if(treat[top+1]<treat[bottom]&&treat[top]>=treat[bottom-1])
            return cache[top][bottom]=max(TRT(top+1,bottom-1)+treat[top],TRT(top+1,bottom-1)+treat[bottom]);
    else
        return cache[top][bottom]=max(TRT(top+1,bottom-1)+treat[top],TRT(top,bottom-2)+treat[bottom]);


}
int main()
{
    int i,j,sum=0;
    while(1){
    scanf("%d",&n);
    if(n==0)
        break;
    count++;
    for(i=0;i<n;i++)
       {
            scanf("%d",&treat[i]);
            sum+=treat[i];
       }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cache[i][j]=0;
        }
    }
    int ans = 2*TRT(0,n-1)-sum;
    printf("In game %d, the greedy strategy might lose by as many as %d points.\n",count,ans);
    sum=0;
    }

}

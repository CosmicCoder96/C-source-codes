#include<stdio.h>
int n;
int treat[2001];
int cache[2001][2001]={0};               //1 2 5 1 4 max(trt(1,4)+1*1,trt(0,3)+1*4)
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
    int year=n+top-bottom;
        return cache[top][bottom]=max(TRT(top+1,bottom)+year*treat[top],TRT(top,bottom-1)+year*treat[bottom]);
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&treat[i]);
    printf("%d",TRT(0,n-1));

}

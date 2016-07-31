#include<stdio.h>
int minCorner(int a,int b)
{
    return a<b?a:b;
}
int minGeneral(int a,int b, int c)
{
    int min=a;
    if(b<min)
        min=b;
    if(c<min)
        min=c;
    return min;
}
int minDP(int h, int w, int DP[][w+1])
{
    int min=DP[0][0],i=0,j=0;
    for(i=0;i<w;i++)
    {
        if(DP[0][i]<min)
            min=DP[0][i];
    }
    if(h==1)
        return min;
    for(i=1;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            if(j==0)
            {
            if(w!=1)
                DP[i][j]=minCorner(DP[i][j]+DP[i-1][j],DP[i][j]+DP[i-1][j+1]);
            else
                DP[i][j]=DP[i][j]+DP[i-1][j];
            }
            else if(j==w-1)
            {
               if(w!=1)
                DP[i][j]=minCorner(DP[i][j]+DP[i-1][j],DP[i][j]+DP[i-1][j-1]);
               else
                DP[i][j]=DP[i][j]+DP[i-1][j];
            }
            else
            {
                DP[i][j]=minGeneral(DP[i][j]+DP[i-1][j],DP[i][j]+DP[i-1][j-1],DP[i][j]+DP[i-1][j+1]);
            }

        }
    }
    min=DP[h-1][0];
    for(i=0;i<w;i++)
    {
        if(DP[h-1][i]<min)
            min=DP[h-1][i];
    }
    return min;

}
int main()
{
    int h,w,i,j;
     scanf("%d %d",&h,&w);
     int DP[h+1][w+1];
     for(i=0;i<h;i++)
     {
         for(j=0;j<w;j++)
         {
             scanf("%d",&DP[i][j]);
         }
     }
     printf("%d\n",minDP(h,w,DP));

}

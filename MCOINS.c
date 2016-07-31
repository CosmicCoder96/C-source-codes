#include<stdio.h>
int k,l,m;
int dp(int n)
{   //printf("hello\n");
    int i;
    int winning[n+1];
    winning[1]=1;
    winning[k]=1;
    winning[l]=1;
    winning[0]=0;
    for(i=1;i<=n;i++)
    {
        if(i>=l&&i>=k)
        {
       if(i==1||i==k||i==l)
        winning[i]=1;

        else if(winning[i-1]==0||winning[i-k]==0||winning[i-l]==0)
        {
            winning[i]=1;
        }
        else
            winning[i]=0;

        }
        else if(i>=l&&i<k)
        {
             if(i==1||i==k||i==l)
        winning[i]=1;

        else if(winning[i-1]==0||winning[i-l]==0)
        {
            winning[i]=1;
        }
        else
            winning[i]=0;

        }
        else if(i>=k&&i<l)
        {
            if(i==1||i==k||i==l)
        winning[i]=1;

        else if(winning[i-1]==0||winning[i-k]==0)
        {
            winning[i]=1;
        }
        else
            winning[i]=0;

        }
        else
        {
             if(i==1||i==k||i==l)
        winning[i]=1;

        else if(winning[i-1]==0)
        {
            winning[i]=1;
        }
        else
            winning[i]=0;

        }
    }
    return winning[n];
}
int main()
{

    scanf("%d %d %d",&k,&l,&m);
    int g[m],result,i;
    char array[m+1];

    for(i=0;i<m;i++)
    {
        scanf("%d",&g[i]);
        result=dp(g[i]);
        //printf("%d\n",result);
        if(result==1)
        {
            array[i]='A';
        }
        else
            array[i]='B';

    }
    array[m]='\0';
    printf("%s",array);


}

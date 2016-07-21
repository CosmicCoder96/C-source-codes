#include<stdio.h>
int a[100000000]={0};
int C[100000000]={0};
int R[100000000]={0};
int rO=0;
int cO=0;
int getposR(rX,rO,n)
{
    int t = rO;
    while(t--)
    {
        rX+=1;
        if(rX>n)
        {
         rX=1;
        }
    }
    return rX;
}
int getposC(cX,cO,n)
{
    int t = cO;
    while(t--)
    {
        cX+=1;
        if(cX>n)
        {
         cX=1;
        }
    }
    return cX;
}
int main()
{
    int n,k,x,r,c,cX,rX,s=0;
    scanf("%d %d",&n,&k);
    while(k--){
    scanf("%d %d %d",&x,&r,&c);
    if(a[x]==0){
    if((x-3)%4==0)
        cX=3;
    else if((x-2)%4==0)
        cX=2;
    else if((x-1)%4==0)
        cX=1;
    else
        cX=4;
    rX = x/4 + 1;
    rX=getposR(rX,rO,n);
    cX=getposC(cX,cO,n);
    C[x]=cX;
    R[x]=rX;
    a[x]=1;
    }

    //printf("%d %d \n",cX,rX);
    if(c>=C[x])
    {
    s+=c-C[x];
    cO+=c-C[x];
    }

    else
    {
        s+= n-C[x]+c;
        cO+= n-C[x]+c;

    }

    if(r>=R[x])
    {
        s+=r-R[x];
        rO+=r-R[x];

    }

    else
    {
        s+=n-R[x]+r;
        rO+=n-R[x]+r;

    }

    printf("%d\n",s);
    C[x]=c;
    R[x]=r;
    s=0;
    }
}

#include<stdio.h>
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int t,x,i,a,b,sq,c;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d %d",&a,&b);
    x = gcd(a,b);
   // printf("%d ",x);
    c=0;
    sq = (int)sqrt(x);

        for(i=1;i<=sq;i++)
        {
            if(x%i==0){
                c+=2;
            if(i==x/i)
                c--;
                }
        }
    printf("%d\n",c);
    }



}

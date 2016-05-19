#include<stdio.h>
int gcd_recursive(int a, int b)
{
    if (b)
        return gcd_recursive(b, a % b);
    else
        return a;
}
int main()
{
    int t,a,b,c,i=1;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d %d %d",&a,&b,&c);
       // printf("%d",gcd_recursive(a,b));
          if (c%gcd_recursive(a,b)==0)
        printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);
        i++;

    }

}

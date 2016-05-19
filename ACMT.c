#include<stdio.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}
int min(int a,int b)
{
    return (a<b)?a:b;
}
int main()
{
    int t,E,N,x,y,z,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&E,&N);
        x = min(E,N);//100

       y = max(E,N);//100

        z = y-x;//0
        w = x -z;//100
        if(z>=x)
            printf("%d\n",x);
        else
        {
            // ene en en en
            if(w%3==0)
                z = z+ w/3 * 2 + 0;
            if(w%3==2)
                z = z + w/3 * 2+ 1;
            if(w%3==1)
                z = z + w/3 * 2 +0;

            printf("%d\n",z);


        }

    }
}

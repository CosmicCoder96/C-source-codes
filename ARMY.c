#include<stdio.h>
int main()
{
    int NG,NM,t,max1=0,max2=0,i,a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&NG,&NM);
        for(i=1;i<=NG;i++)
        {
            scanf("%d",&a);
            if(a>=max1)
                max1=a;
        }
         for(i=1;i<=NM;i++)
        {
            scanf("%d",&a);
            if(a>=max2)
                max2=a;
        }
        if(max1==0||max2==0)
            printf("uncertain\n");

        else if(max1>=max2)
        printf("Godzilla\n");
    else
        printf("MechaGodzilla\n");
    max1=0;
    max2=0;

    }


}


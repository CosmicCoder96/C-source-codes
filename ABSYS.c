#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a[100],b[100],c[100],op,eq,la,lb,lc;
        int flag=0,i,A,B,C;
        scanf("%s %c %s %c %s",a,&op,b,&eq,c);
        la = strlen(a);
        lb = strlen(b);
        lc = strlen(c);
        for(i=0;i<la;i++)
        {
            if(a[i]=='m')
                {
                flag = 1;
                break;
                }
        }
        if(i==la)
             A = atoi(a);
        for(i=0;i<lb;i++)
        {
            if(b[i]=='m')
                {
                flag = 2;
                break;
                }
        }
        if(i==lb)
             B = atoi(b);
        for(i=0;i<lc;i++)
        {
            if(c[i]=='m')
                 {
                flag = 3;
                break;
                }
        }
        if(i==lc)
         C = atoi(c);
        if(flag==3)
        {
            printf("%d + %d = %d\n",A,B,A+B);
        }
        if(flag==2)
        {
            printf("%d + %d = %d\n",A,C-A,C);
        }
        if(flag==1)
        {
            printf("%d + %d = %d\n",C-B,B,C);
        }



    }
    return 0;
}

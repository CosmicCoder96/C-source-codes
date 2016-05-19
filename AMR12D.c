#include<stdio.h>
int main ()
{

    int t,i,l;
    scanf("%d",&t);
    while(t--)
    {
        char a[20],b[20];
        i = 0;
        scanf("%s",a);
        l = strlen(a);
        while(a[i]!='\0')
        {
            b[i] = a[l-i-1];
            i++;
        }
        for(i=0;i<l;i++)
        {
            if(a[i]!=b[i])
                break;
        }
        if(i==l)
            printf("YES\n");
        else
            printf("NO\n");


    }


}

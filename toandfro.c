#include<stdio.h>
#include<string.h>
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
int main()
{
    int t,i,j,l,cc;
    while(1<2)
    {
        scanf("%d",&t);//5
        if(t==0)
            break;
        char a[201];
        scanf(" %s",a);
        l = strlen(a);//35
        cc = l/t;//7
        int x=0;
        char c[cc][t+1];
        for(i=0;i<cc;i++)
        {
            for(j=0;j<t;j++)
            {
                c[i][j]=a[x];
                x++;
            }
            c[i][j]='\0';
            if(i%2==1)
            strrev(c[i]);
        }
    for(j=0;j<t;j++){
        for(i=0;i<cc;i++)
        {

                printf("%c",c[i][j]);



        }
    }
    printf("\n");

    }

    return 0;
}

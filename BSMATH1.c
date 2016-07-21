#include<stdio.h>
#include<string.h>
int base[37]={0};
char A[1000],op,B[1000],e,C[1000];
int findBase()
{
    long long int i,j,a=0,b=0,c=0,l1,l2,l3,flag,x;
    l1 = strlen(A);
    l2 = strlen(B);
    l3=strlen(C);
    for(i=2;i<=36;i++)
    {
        if(base[i]==0){
        flag=0,a=0,b=0,c=0;
        for(j=0;j<=l1-1;j++)
        {
            x = A[j]-'0';
            if(x>9)
                x-=7;
            if(x>=i)
            {
                flag=1;
                break;
            }
            a = a + (A[j]-'0')*pow(i,l1-1-j);
        }
         if(flag==1)
            continue;
      //  printf("\n%lld",a);
        for(j=0;j<=l2-1;j++)
        {
            x = B[j]-'0';
            if(x>9)
                x-=7;
            if(x>=i)
            {
                flag=1;
                break;
            }
            b = b + (B[j]-'0')*pow(i,l2-1-j);
        }
        //printf("\n%lld",b);
        if(flag==1)
            continue;
        for(j=0;j<=l3-1;j++)
        {
            x = C[j]-'0';
            if(x>9)
                x-=7;
            if(x>=i)
            {
                flag=1;
                break;
            }
            c = c + (C[j]-'0')*pow(i,l3-1-j);
        }
        if(flag==1)
            continue;
        //printf("\n%lld",c);
        if((a+b)==c||(a-b)==c)
        {
           base[i] = 1;
            return i;
        }
        }

    }
}
int main()
{
   int n,l1,t,l2,a,b,c,base,i,l3;
   scanf("%d",&n);

   scanf("%s %c %s %c %s",A,&op,B,&e,C);
   printf("%d\n",findBase());
   base=findBase();
   scanf("%d",&t);
   while(t--)
   {
       scanf("%s %c %s %c ",A,&op,B,&e);
        l1 = strlen(A);
        l2 = strlen(B);
        a=0;
        b=0;
        c=0;
        //l3=strlen(C);
        for(i=0;i<l1;i++)
            a+=A[i]*pow(base,l1-i-i);
        for(i=0;i<l2;i++)
            b+=B[i]*pow(base,l2-i-i);
   //     for(i=0;i<l3;i++)
     //       c+=C[i]*pow(base,l3-i-i);
        printf("%lld\n",a+b);


   }


}

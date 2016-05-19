#include<stdio.h>
int main()
{
long long int t;
int r,c,x=0,i,j;
scanf("%lld",&t);
while(t--)
{
  scanf("%d %d",&r,&c);
  for(i=1;i<=r;i++)
  {

      for(j=1;j<=c;j++)
      {
           if(x==1){
            printf(".");
            x=0;
            continue;
            }
        if(x==0)
        {
            printf("*");
            x=1;
        }


      }
      printf("\n");
      if((i+1)%2==0)
        x=1;
      else
        x=0;

  }
  printf("\n");
 x=0;
}
return 0;
}


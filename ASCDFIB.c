#include<stdio.h>
int count[1100000]={0};
void count_sort(int a[],int n,int max)
{
     int i,j,k=0,flag=0;

    memset(count, 0, sizeof(count));
     for(i=0;i<n;++i)
      count[a[i]]=count[a[i]]+1;
     for(i=0;i<=max;++i)
     {


      for(j=1;j<=count[i];++j)
      {
          k++;
          printf(" %d",i);
          if(k==100)
          {
              flag=1;
              break;
          }

      }
      if(flag==1)
        break;
     }


}
void fib(int a, int b)
{
    int i,count =0,f[a+b],ar[b+2],max=0;
    f[1]=0;
    f[2]=1;
    for(i=3;i<=a+b;i++)
        f[i]=(f[i-1]+f[i-2])%100000;
    for(i=a;i<=a+b;i++)
    {
        ar[count++]=f[i];
    if(f[i]>max)
        max=f[i];

    }
    count_sort(ar,count,max);



}
int main(){
int a,b,c,d;
scanf("%d",&c);
d=c;
while(c--)
{
scanf("%d %d",&a,&b);
printf("Case %d:",d-c);
fib(a,b);
printf("\n");
}
return 0;
}

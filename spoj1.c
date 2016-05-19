#include<stdio.h>
#include<stdlib.h>
void qisort(long long int arr[][2], long long int fst, long long int last);
void qisort(long long int arr[][2], long long int fst,  long long int last)
{
 int i,j,pivot,tmp;
 if(fst<last)
 {
   pivot=fst;
   i=fst;
   j=last;
   while(i<j)
   {
     while(arr[i][0]<=arr[pivot][0] && i<last)
        i++;
     while(arr[j][0]>arr[pivot][0])
        j--;
     if(i<j)
     {
        tmp=arr[i][0];
        arr[i][0]=arr[j][0];
        arr[j][0]=tmp;
     }
   }
   tmp=arr[pivot][0];
   arr[pivot][0]=arr[j][0];
   arr[j][0]=tmp;
   qisort(arr[0],fst,j-1);
   qisort(arr[0],j+1,last);
 }}
int main()
{

    long long int t,i,n,c[100000];
    int flag=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
       long long int a[n][2];
        for(i=0;i<n;i++)
        {
            scanf("%lld %lld",&a[i][0],&a[i][1]);

        }
        //c=a;
         qisort(a,  0,n-1);
         for(i=0;i<n;i++){
            if(a[i][0]=a[i+1][0])
                c[i]++;
//            b[i]=a[i][1];

         }

         //qisort(b,0,n-1);
        for(i=0;i<n;i++)
        {
            printf("%lld %lld\n",a[i][0],a[i][1]);
        }

        //free(a);
//        free(b);



    }

return 0;
}

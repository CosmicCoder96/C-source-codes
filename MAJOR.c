#include<stdio.h>
int main()
{

    int t,x,y,i,z,n,c;
    scanf("%d",&t);
    while(t--)
    {
        c = 0;
        scanf("%d",&n);
        x = n/2+1;
        //if(x==1){
       // printf("NO\n\n");
      //  continue;


        int a[n];
        int b[100001]={0};
        for(i=0;i<n;i++)
        {

            scanf("%d",&a[i]);
            y=a[i];
            if(a[i]<0)
                y = a[i]+3000;
            //printf("FLAG1\n");
            b[y]+=1;
            if(b[y]>=x)
                z=y;

        }

        if(b[z]>=x)
        {   if (z >1000)
                z-=3000;


            printf("YES %d\n\n", z);
        }
        else
            printf("NO\n\n");

    }
return 0;

    }





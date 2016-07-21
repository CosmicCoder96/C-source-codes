#include<stdio.h>
//2 6 12 20
//1 3 6
int binary(int c, int status, int count, int min)
{
    status=status + (count+1)*c;
    //printf("%d\n", status);
    if(min%status==0)
        return 1;
    else
        return 0;

}
int main()
{
    int t,p,i,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&p);
        scanf("%d",&c);
        int a[c],status[c],countc[c];
        for(i=0;i<c;i++)
            {
                scanf("%d",&a[i]);
                status[i]=0;
                countc[i]=0;

            }
        int minutes=0,count=0;
        while(1)
        {
            minutes++;
            for(i=0;i<c;i++)
                {
            if(binary(a[i],status[i],countc[i],minutes)==1)
                {
                    count++;
                    countc[i]++;
                    status[i]+=countc[i]*a[i];
                    //printf("%d %d\n",status[i],a[i]);
                }

            if(count==p)
            {
                break;
            }
            }
            if(count==p)
            {
                break;
            }

        }
        printf("%d\n",minutes);


    }
}

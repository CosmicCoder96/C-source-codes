#include<stdio.h>
#define air 1
#define water 2
#define fire 3
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int time =0,current=water,H,A,h,a;
        scanf("%d %d",&H,&A);
        while(H>0&&A>0)
        {
            if(current==water||current==fire)
            {
                time++;
                current=air;
                H+=3;
                A+=2;
            }
            else if(current==air)
            {
                h=H-5;
                a = A-10;
                if(A-10<H-20)
                    {
                    current=fire;
                    H-=20;
                    A+=5;
                    if(H>0&&A>0)
                        time++;

                    }
                else
                {
                    H-=5;
                    A-=10;
                    current = water;
                    if(H>0&&A>0)
                        time++;


                }



            }
        }
        printf("%d\n",time);
    }
}

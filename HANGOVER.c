#include<stdio.h>
int main()
{
    float i,n;
    while(1)
    {
        float s =0.00;
        scanf("%f",&n);
        if(n==0.00)
            break;
        for(i=2;;i++)
        {
            s = s + 1/i;
            if(s>=n){
                printf("%.f card(s)\n",i-1);
                break;}
        }
    }
}

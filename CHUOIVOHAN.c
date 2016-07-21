#include<stdio.h>
int main()
{

    long long int a,b,c,s,sequenceNo;
    scanf("%lld %lld %lld",&a,&b,&c);
    sequenceNo=a;
    if(c>=0){
    while(1)
    {
        if(sequenceNo==b)
        {
            printf("YES");
            break;
        }
        else if(sequenceNo>b)
        {
            printf("NO");
            break;
        }

        sequenceNo = sequenceNo + c;
    }
    }
    else
    {
          while(1)
    {
        if(sequenceNo==b)
        {
            printf("YES");
            break;
        }
        else if(sequenceNo<b)
        {
            printf("NO");
            break;
        }

        sequenceNo = sequenceNo + c;
    }

    }


}

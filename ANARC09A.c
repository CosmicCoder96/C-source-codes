#include<stdio.h>
#include<string.h>
int main()
{
    int l,i,j=0,lflag,rflag,matchflag,count;
    while(1)
    {
        char s[4000];
        j++;
        lflag=0;
        rflag=0;
        count=0;
        int ans;
        scanf("%s",s);
        l=strlen(s);
        if(s[0]=='-')
            break;
        // printf("hello");          //   {{{{{{{}{}}}
        for(i=0;i<l;i++)
        {
            if(s[i]=='{')
                lflag++;
       // printf("hello");
            else
            {
               // printf("hello");
                lflag--;
                if(lflag<0)
                    {
                    count++;
                    lflag=1;
                    }
            }
        }

        ans=count+ lflag/2;
        printf("%d. %d\n",j,ans);
    }
}

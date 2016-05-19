#include<stdio.h>
#include<string.h>
int main()
{


        char s[100001];

        while(scanf("%s",s)!=EOF)
        {
        int l,c,i;


        l = strlen(s);


        c=1;
        for(i=0;i<l;i++){
                c=1;
        while(s[i]==s[i+1]){
            c++;i++;}
        if(c>3)
            printf("%d!%c",c,s[i-1]);
          else if(c==3)
            printf("%c%c%c",s[i-1],s[i-1],s[i-1]);
        else if(c==2)
            printf("%c%c",s[i-1],s[i-1]);
         else if(c==1)
            printf("%c",s[i]);

        }
        printf("\n");


    }
    return 0;
}

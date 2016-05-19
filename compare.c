#include<stdio.h>
int main()
{

//char a[1000002]
int t,k,l,c;
long long int i=0;
scanf("%d",&t);
while(t--)
{

        //printf("%d",'Z');
        char a[1000002]="",b[1000002]="";
        scanf("%d",&k);
        scanf(" %s",a);
        l = strlen(a);
        if(k<=25){
        for(i=0;i<l;i++){
        c = ((int)a[i] + k%26);
        if(a[i]>='a'&&a[i]<='z'&&c>122)
            c=c-26;
        //if((a[i]>=65&&a[i]<=91)||(c>=97&&c<=122))
        if(a[i]>='A'&&a[i]<='Z'&&c>90)
        c = c-26;
        b[i]=(char)c;

        if(a[i]=='.')
            b[i]=' ';
        }}
        if(k>25)
        {for(i=0;i<l;i++){
           c = ((int)a[i] + k%26);
        if(a[i]>='a'&&a[i]<='z'&&c>122)
            c=c-26;
        if(a[i]>='A'&&a[i]<='Z'&&c>90)
            c = c-26;

         if(a[i]>='a'&&a[i]<='z')
            c=c-32;

         if(a[i]>='A'&&a[i]<='Z')
            c=c+32;
        b[i]=(char)c;

        if(a[i]=='.')
            b[i]=' ';
        }
        }



        printf("%s\n", b);
//        s="";



}





    return 0;
}

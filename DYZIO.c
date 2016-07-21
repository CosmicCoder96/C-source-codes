#include<stdio.h>
void cut(int s[], int n, int *cutcount);;
int main()
{
    int t = 10,n,i,x;
    while(t--)
    {
        int cutcount = 0;
        scanf("%d",&n);
        char st[n+1];
        int s[n];
        scanf("%s",st);
        for(i=0;i<n;i++)
            s[i] = st[i]-'0';

      cut(s,n,&cutcount);
        printf("%d\n",cutcount);
    }
    return 0;
}




void cut(int s[], int n, int* cutcount)// i--0 //110011000
{
static int bitcount = 0;
if(bitcount==n-1)
return;
if(s[bitcount]==0&&bitcount==0)
{

return ;
}
if(s[bitcount]==0)
{
bitcount ++;
return ;
}
if(s[bitcount]==1)
bitcount ++;//1/2
(*cutcount)++;//1/2;
cut(s,n,cutcount);//2/3/4
cut(s,n,cutcount);//2//

}

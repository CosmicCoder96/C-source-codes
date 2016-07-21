#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{

    int t,l,i,k;
    scanf("%d",&t);
    while(t--)
    {
        char n[1000000];
        scanf("%s %d",n,&k);
        l = strlen(n);
        int a[l];
        for(i=0;i<l;i++)
        {
            a[i]=n[i]-'0';
        }
        //sort(a,a+l);
        for(i=l-1;k>=0;i--)
        {
            printf("%d",a[i]);
            k--;
        }



    }
}

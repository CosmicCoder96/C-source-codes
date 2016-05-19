#include<stdio.h>
int mod(char a[],int b)
{
	int i, l = strlen(a),d=0,m;
	for(i=0;i<l;i++)
	{
		m = a[i]-'0' + 10*d;
		d = m%b;
	}
	return d;
}
int main()
{
    int t,m1,m2;
    scanf("%d",&t);
    while(t--)
    {
        char s[1000000];
        scanf("%s",s);
        m1 = mod(s,252);
        m2 = mod(s,525);
        if(m1==0&&m2==0)
            printf("Yes Yes\n");
        if(m1!=0&&m2!=0)
            printf("No No\n");
        if(m1==0&&m2!=0)
            printf("Yes No\n");
        if(m1!=0&&m2==0)
            printf("No Yes\n");


    }
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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
int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}


int main()
{
int t,a;
scanf("%d",&t);
while(t--)
{
int b;
char s[100000];
scanf("%d %s",&b,s);


if(s[0]-'0'==0)
printf("%d\n",b);
else if(b==0)
printf("%s\n",s);
if(s[0]-'0'!=0&&b!=0){
a = mod(s,b);
printf("%d\n",gcd(b,a));}

}
return 0;
}



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

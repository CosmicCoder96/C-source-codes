#include<stdio.h>
int fi(int n) {
		int result = n;
		int i;
		for( i=2;i*i <= n;i++) {
			if (n % i == 0) result -= result / i;
			while (n % i == 0) n /= i;
		}
		if (n > 1) result -= result / n;
		return result;
	}
int main()
{
    int t;
    int n,a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        printf("%d\n",fi(a));
    }
    return 0;
}

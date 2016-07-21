#include<stdio.h>
#define gc getchar_unlocked
long long int s[100001]={0};
long long int sq[100001]={0};
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
int main()
{
    long long int n,i,m;
    scanf("%lld",&n);
    s[0]=n;
    sq[0]=n*n;
    for(i=1;i<n;i++)
    {
        scanf("%lld",&n);
        s[i] = s[i-1]+n;
        sq[i] = sq[i-1]+n*n;

    }
    scanf("%lld",&m);
    int a,b;
    while(m--)
    {
        scanf("%d %d",&a,&b);
        printf("%lld\n",(s[b]-s[a]+sq[b]-sq[a])/2);
    }


}

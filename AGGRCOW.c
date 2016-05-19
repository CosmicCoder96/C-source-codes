#include<iostream>
#include<algorithm>
#include<cstdio>
int cow(int x);
int stalls[100001];
long long int t,N,C;
int main()
{

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&N,&C);

    }
}
int cow(int x)
{
int cowsp = 1;
lastp = a[0];
for(i=1;i<n;i++){
    if(arr[i]-lastp>=x)
        cowsp++;
    if(cowsp==C)
        return 1;
    lastp = a[i];
}
return 0;


}

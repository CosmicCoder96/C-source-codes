#include<iostream>
using namespace std;
#define ll long long
#define MOD 1000000007
ll modular_pow(ll base, ll exponent)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % MOD;
        exponent = exponent >> 1;
        base = (base * base) % MOD;
    }
    return result;
}
ll mod_inverse(ll num)
{
    return modular_pow(num,MOD-2);
}
ll ncr(ll n , ll r)
{
    r = min(n-r,r);
    if(n==0||n==1||r==0)
        return 1;
    ll num=1;
    for(ll i =n;i>=n-r+1;i--)
        num = (num*i)% MOD;
    ll den = 1;
    for(ll i = 1;i<=r;i++)
    {
        den=(den*i)%MOD;

    }
    den = mod_inverse(den);
    ll res = (num*den)%MOD;
    return res;
}
int main()
{
    ll n,w,t,r,res;
    cin>>n>>w>>t>>r;
    res = ncr(n,w);
    n-=w;
    res=(res*ncr(n,t))%MOD;
    n-=t;
    res = (res*ncr(n,r))%MOD;
    cout<<res<<endl;




}

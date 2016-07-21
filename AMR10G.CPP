#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
     long long int t,i,n,k,minH,c=0,d=0,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        if(k==1){
            cout<<0<<endl;
            continue;
        }
        minH = a[n-1]-a[n-2];
        for(i=0;i+k-1<n;i++)
        {
            d = a[i+k-1]-a[i];
            if(d<minH)
                minH=d;
        }



        cout<<minH<<endl;
        d =0;
        c=0;


    }
}

#include<iostream>
#include<cmath>
using namespace std;
int main()
{

    int t,n,i,s=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1){
            cout<<0<<endl;
            continue;
        }

        for(i=2;i<=sqrt(n);i++)
        {
            if(n%i==0){
                s = s+i;
                if(i!=(n/i))
                s = s + n/i;
               // cout<<s<<" "<<i<<endl;
        }
            //cout<<s<<" "<<i<<endl;}
            }
        cout<<s+1<<endl;
        s = 0;

    }
}

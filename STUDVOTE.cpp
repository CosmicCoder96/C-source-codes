#include<iostream>
using namespace std;

int main()
{
    int i,t,n,k;

    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int a[n+1];
        int cnt=0;
        int vote[1000]={0};
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==i)
                vote[i]=-1;

        }
        for(i=1;i<=n;i++)
        {
            if(vote[a[i]]!=-1)
            {
                vote[a[i]]++;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(vote[i]>=k)
                cnt++;
        }
        cout<<cnt<<endl;
        cnt=0;

    }
}

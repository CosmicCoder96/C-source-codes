#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,x,i,k,c=0,max;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    i=0;
    cin>>k;
    max = a[0];
    for(i=0;i<n;i++)
    {
        c++;
        if(a[i]>max)
            max = a[i];
        if(c==k)
        {
            cout<<max<<" ";
            c = 1;
            if(i+1==n)
                exit(0);
            max = a[i+1];
        }

    }



}

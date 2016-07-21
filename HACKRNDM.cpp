#include<iostream>
#include<algorithm>

using namespace std;
int difference(int a[], int first, int last,int x,int k);
int c =0;
int a[1000000];
int main()
{
    int n,k,s=0,i;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++){
        s = s + difference(a,0,n-1,a[i],k);
        //c=0;
    }
    cout<<s;
 //for(i=0;i<n;i++)
    //cout<<a[i]<<" ";
}

int difference(int a[], int first, int last,int x,int k)
{
int mid;
    if(first<=last){
     mid = first + (last-first)/2;
   // cout<<mid<<endl;
    if((x-a[mid])==-k){
      //  cout<<x<<" "<<a[mid]<<" "<<endl;
        return 1;
    }
    else if ((x-a[mid])>(-k))
    {
       //  cout<<x<<" "<<a[mid]<<" "<<endl;
        return difference(a,mid+1,last,x,k);
    }
    else
    {
        // cout<<x<<" "<<a[mid]<<" "<<endl;
        return difference (a,first,mid-1,x,k);
    }
    }
    else
        return 0;

}

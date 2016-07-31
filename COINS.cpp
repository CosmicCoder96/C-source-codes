#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<long long int,long long int> coinsB;
long long int coins[100000000];
long long int maxC(long long int a, long long int b)
{
    return a>b?a:b;
}
long long int byteR(long long int n)
{
    if(n==0)
        return 0;
    if(n<=10000000)
    {
        return maxC((coins[n/4]+coins[n/3]+coins[n/2]),n);
    }
    return maxC((byteR(n/4)+byteR(n/3)+byteR(n/2)),n);
}
long long int byte(long long int n)
{



    long long int i;
    coins[0]=0;

    for(i=1;i<=n;i++)
    {
         coins[i]=maxC((coins[i/4]+coins[i/3]+coins[i/2]),i);
    }

    return coins[n];
}
int main()
{

 long long int n;
 while(cin>>n)
 {
     if(n<=10000000)
     cout<<byte(n)<<endl;
     else
        cout<<byteR(n)<<endl;
 }

}

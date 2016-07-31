#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int DP[6101][6101];
int palin(string r, string s, int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        DP[0][i]=DP[i][0]=0;

    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(s[i-1]==r[j-1])
                DP[i][j] = DP[i-1][j-1]+1;
            else
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
        }
    }
    return DP[n][n];
}
int main()
{
    int t,i=0,lcs,l;
    cin>>t;
    while(t--)
    {
        string s,r,p,f;
        cin>>s;
        r = s;
        reverse(s.begin(),s.end());
        l = s.length();
        lcs = palin(s,r,l);
        cout<<l-lcs<<endl;

                                
                                

    }
}


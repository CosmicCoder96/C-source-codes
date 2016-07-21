#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main()
{
    int t;
    long double r1,r2,r3,x;
    cin>>t;
    while(t--)
    {
        cin>>r1>>r2>>r3;
        x = (r1*r2*r3)/(((r1*r2) + r2*r3 + r1*r3) + 2*(sqrt(r1*r2*r3*(r1+r2+r3))));
        cout<<fixed;
        cout<<setprecision(50);
        cout<<x<<endl;
    }
}

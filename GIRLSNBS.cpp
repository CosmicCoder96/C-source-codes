#include<iostream>
using namespace std;
int main()
{
    int G,B,x;
    while(1)
    {
    cin>>G>>B;
    if(G==-1)
        break;

    if(G>B)
    {
        x = G/(B+1);
        if(G%(B+1)!=0)
            x++;
        cout<<x<<endl;

    }

    else if (B>=G)
        {
              x = B/(G+1);
        if(B%(G+1)!=0)
            x++;
        cout<<x<<endl;
        }


    }
    return 0;
}

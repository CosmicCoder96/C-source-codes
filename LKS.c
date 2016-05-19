#include<stdio.h>
int max(int a, int b) { return (a > b)? a : b; }
int main()
{
    int S,N,i,j;

    scanf("%d %d",&S,&N);
    int s[N];int v[N];
    for(i=0;i<N;i++)
    {

            scanf("%d %d",&v[i],&s[i]);

    }
    int vtable[N+1][S+1];
    //N=sizeof(v)/sizeof(v[0]);
    for(i=0;i<=N;i++){
        for(j=0;j<=S;j++)
        {
            if(i==0||j==0){
                vtable[i][j]=0;
//                ktable[i][j]=0;
        }
       else  if(s[i-1]<=j)
        {

            vtable[i][j] = max(v[i-1]+vtable[i-1][j-s[i-1]],vtable[i-1][j]);

        }
        else
            vtable[i][j]=vtable[i-1][j];
            }

        }
        printf("%d",vtable[N][S]);
        return 0;
        }


#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
#define temporary 1
#define permanent 2
int adj[MAX][MAX];
int status[MAX];
int distance[MAX][MAX];
int main()
{
    int i,v,n,t,k,x=0;
    int **adj = (int**)malloc(sizeof(int*)*10001);
    for(i=0;i<10001;i++)
        adj[i]=(int*)malloc(sizeof(int)*10001);
    memset(adj,0,sizeof(adj[0][0])*10001*10001);
       for(i=0;i<10001;i++)
    {
        for(v=0;v<10001;v++)
            printf("%d ",adj[i][v]);
        }

}



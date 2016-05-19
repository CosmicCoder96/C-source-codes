#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 0
#define waiting 1
#define visited 2


void BFS(int v, int adj[][100],int status[],int distance[],int Q[],int predecessor[],int * front , int *rear,int n);
int DeQ(int Q[],int * front ,int * rear);
void EnQ(int Q[],int x,int * front, int * rear);

int main()
{
    int adj[100][100]={0};
    int status[100]={initial};
    int distance[100],predecessor[100],path[100];
    int Q[MAX];
    int n,front = -1,rear = -1,u,v,i,e,x,y=0;
    scanf("%d",&n);
    for(i=0;i<n*(n-1);i++)
    {
        scanf("%d %d",&u,&v);
        if(u==-1&&v==-1)
            break;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    scanf("%d",&v);
    BFS(v,adj,status,distance,Q,predecessor,&front,&rear,n);
    scanf("%d",&e);
    printf("%d\n",distance[e]);
    while(e!=-1)
    {
    path[y]=e;
    x = predecessor[e];
    e = x;
    y++;
    }
    for(i=y-1;i>=0;i--)
    {
        printf("%d ",path[i]);
    }





}

void EnQ(int Q[],int x,int * front, int * rear)
{
    if(*front==-1)
        *front = *front + 1;
    if(*rear>=MAX-1)
        return;
    *rear = *rear + 1;
    Q[*rear]=x;
    return;


}
int DeQ(int Q[],int * front ,int * rear)
{
    int x;
    if(*front==-1||*front>*rear)
        return -9999;
    else
         x = Q[*front];
        *front = *front + 1;
        return x;
}
void BFS(int v, int adj[][100],int status[],int distance[],int Q[],int predecessor[],int * front , int *rear,int n)
{
    int i;
    EnQ(Q,v,front,rear);
    status[v]=waiting;
    predecessor[v]=-1;
   // printf("%d ",status[v]);
    distance[v]=0;
    while(*front<=*rear)
    {
        v = DeQ(Q,front,rear);
        status[v] = visited;
        for(i=0;i<=MAX;i++)
        {
            if(adj[v][i]==1&&status[i]==initial)
            {
                EnQ(Q,i,front,rear);
                status[i]=waiting;
                distance[i]=distance[v]+1;
                predecessor[i] = v;
            }
        }

    }



}

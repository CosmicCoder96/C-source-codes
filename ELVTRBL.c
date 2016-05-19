#include<stdio.h>
#define initial 0
#define waiting 1
#define visited 2
#define MAX 1000001
int Q[1000001],state[1000001]={initial},distance[1000001];
void EnQ(int Q[],int x,int *front,int *rear)
{
    if(*front==-1)
        *front =0;
    if(*rear==MAX-1)
       return;
    *rear = *rear +1;
    Q[*rear] = x;
  //  printf("\nEnqued\n");
    return;
}
int DeQ(int Q[],int *front,int *rear)
{
    if(*front==-1||*front>*rear)
        return -1;
    int z = Q[*front];
    *front = *front + 1;
   //  printf("\nDequed\n");
    return z;
}
void DFS(int f, int s, int g, int u, int d, int * front, int * rear)
{
    int k,l;
    EnQ(Q,s,front,rear);
    state[s] = waiting;
    distance[s] = 0;

       while(*front<=*rear)
    {
        s = DeQ(Q,front,rear);
        state[s] = visited;
        k = s + u;
        l = s- d;

        if(k<=f && state[k]==initial)
        {
            EnQ(Q,k,front,rear);
            state[k] = waiting;
            distance[k] = distance[s] + 1;
        }
        if(l>=1&&state[l]==initial)
        {
          EnQ(Q,l,front,rear);
            state[l] = waiting;
            distance[l] = distance[s] + 1;
        }
    }
    if(state[g]==visited)
        printf("%d\n",distance[g]);
    else
        printf("use the stairs\n");
}
int main()
{
    int f,s,g,u,d,front = -1, rear = -1;
    scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
    if(s==g)
        printf("0\n");
    else
    DFS(f,s,g,u,d,&front,&rear);
}

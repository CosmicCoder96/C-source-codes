#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define gc getchar
#define infinity 99999
#define MAX 10001
#define NIL -1
#define initial 0
#define waiting 2
#define visited 3
int adj[10000][10000];
//int state[10000];
int distance[10000];
int Q[10000];
int max=0,max_index=0;
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
void EnQ(int x,int *front,int *rear)
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
int DeQ(int *front,int *rear)
{
    if(*front==-1||*front>*rear)
        return -1;
    int z = Q[*front];
    *front = *front + 1;
   //  printf("\nDequed\n");
    return z;
}
void BFS(int v,int n, int*front,int *rear)
{
    int i;
  //  for(i=1;i<=n;i++)
  //{
  //      state[i]=initial;
       // distance[i]=infinity;
 //   }

       int state[10000]={0};
    //   memset(state,initial,sizeof(state));
       // memset(distance,infinity,sizeof(distance));
       // predecessor[i]=NIL;
       // Q[i]=0;


    EnQ(v,front,rear);
    state[v]=waiting;
    distance[v]=0;

    while(*front<=*rear)
    {
        v = DeQ(front,rear);
		state[v] = visited;
		for(i=1; i<=n; i++)
		{

			if( adj[v][i] == 1 && state[i] == initial)
			{
				EnQ(i,front,rear);
				state[i]=waiting;

				distance[i] = distance[v]+1;
				if(distance[i]>max)
                    {
                    max=distance[i];
                    max_index=i;
                    }

			}
        }
	}
}



int main()
{
int n,u,v,i,m;
scanf("%d",&n);
m=n-1;


while(m--)
{
   //scanf("%d %d",&u,&v);
   u = read_int();
   v=read_int();
    adj[u][v]=1;
    adj[v][u]=1;
}
    int front =-1,rear=-1;
    if(n>1){
    BFS(1,n,&front,&rear);
    //for(i=1;i<=n;i++)
    //max1=max;
    //printf("%d\n",max);
    max=0;
    front=-1,rear=-1;
    BFS(max_index,n,&front,&rear);
  //  max2=max;
   // max3=max1+max2;
    printf("%d",max);


    }
    else
        printf("0");

/*else{
    scanf("%d %d",&u,&v);
    printf("%d",abs(u-v));
}*/

}


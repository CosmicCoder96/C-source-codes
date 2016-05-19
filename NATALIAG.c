#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
#define initial 0
#define waiting 2
#define visited 3
struct node{
    int cordX;
    int cordY;
};
void EnQ(struct node Q[],int x,int y,int * front, int * rear)
{
    if(*front==-1)
        *front = *front + 1;
    if(*rear>=MAX-1)
        return;
    *rear = *rear + 1;
    Q[*rear].cordX = x;
    Q[*rear].cordY = y;
   // printf("\nEnqued\n");
    return;

}
struct node DeQ(struct node Q[] ,int * front, int * rear)
{
    //if(*front==-1||*front>*rear)
    //    return ;
    struct node z = Q[*front];
    *front = * front + 1;
    //printf("\Dequed\n");
    return z;
}
void BFS(struct node Q[],int maze[][101], int status[][101], int distance[][101],int xi , int yi,int xf,int yf,int M, int N,int* front,int*rear)
{
    EnQ(Q,xi,yi,front,rear);
    status[xi][yi]=waiting;
    distance[xi][yi]=0;
    int xtemp,ytemp,x,y;
    struct node z;

    while(*front<=*rear)
    {
        z = DeQ(Q,front,rear);
        x = z.cordX;
        y = z.cordY;
        status[x][y] = visited;
        xtemp = x + 1;
        ytemp = y;
        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,front,rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
        xtemp = x - 1;
        ytemp = y;
        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,front,rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
        xtemp = x;
        ytemp = y + 1;
        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,front,rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
        xtemp = x;
        ytemp = y - 1;
        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,front,rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
        xtemp = x + 1;
        ytemp = y + 1;
        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,front,rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
        xtemp = x - 1;
        ytemp = y + 1;
        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,front,rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
        xtemp = x - 1;
        ytemp = y - 1;
        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,front,rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
        xtemp = x + 1;
        ytemp = y - 1;
        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,front,rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }


    }
    if(status[xf][yf]!=visited)
    printf("-1\n");
    else
    printf("%d\n",distance[xf][yf]);
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int M,N,ei,ej,i,j,gi,gj,Qx={0},Qy={0},front = -1, rear = -1;
        char c;
        char s[1000];
        struct node Q[10010];
        scanf("%d %d",&M,&N);
        int maze[101][101]={0};
        int status[101][101] = {0};

        int distance[101][101] = {0};
       // printf("0000");
        for(i=1;i<=M;i++)
        {
            scanf("%s",s);
            for(j=1;j<=N;j++)
            {
                c=s[j-1];
                if(c=='S')
                {
                    maze[j][i] = 1;
                    ei = j;
                    ej = i;
                }
                if(c=='F')
                {
                    maze[j][i] = 1;
                    gi = j;
                    gj = i;
                }
                if(c=='.')
                {
                    maze[j][i] = 1;

                }
                 if(c=='X')
                {
                    maze[j][i] = -1;

                }

            }
        }
        if(ei==gi&&ej==gj)
            printf("0\n");
        else
        BFS(Q,maze,status,distance,ei,ej,gi,gj,M,N,&front,&rear);
    }
}

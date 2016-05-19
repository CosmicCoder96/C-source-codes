#include<stdio.h>
#include<stdlib.h>
#define MAX 100001
#define initial 0
#define waiting 2
#define visited 3
struct node{
     int cordX;
     int cordY;
};
void EnQ(struct node Q[], int x, int y, int * front,  int * rear)
{
    if(*front==-1)
        *front = *front + 1;
//    if(*rear>=MAX-1)
  //      return;
    *rear = *rear + 1;
    Q[*rear].cordX = x;
    Q[*rear].cordY = y;
  // printf("\nEnqued %d %d\n",Q[*rear].cordX,Q[*rear].cordY);
    return;

}
struct node DeQ(struct node Q[] , int * front,  int * rear)
{
    //if(*front==-1||*front>*rear)
    //    return ;
    struct node z = Q[*front];
    *front = * front + 1;
  //  printf("\Dequed\n");
    return z;
}


        struct node Q[1000000];
int main()
{
    int n,i,j;
    int **distance = (int**)malloc(sizeof(int*)*1001);
    for(i=0;i<1001;i++)
        distance[i]=(int*)malloc(sizeof(int)*1001);
    int **status = (int**)malloc(sizeof(int*)*1001);
    for(i=0;i<1001;i++)
        status[i]=(int*)malloc(sizeof(int)*1001);
    int **maze = (int**)malloc(sizeof(int*)*1001);
    for(i=0;i<1001;i++)
        maze[i]=(int*)malloc(sizeof(int)*1001);
         for(i=0;i<1001;i++)
    {
        for(j=0;j<1001;j++)
        {
            distance[i][j]=0;
            status[i][j]=0;
            maze[i][j]=-1;
        }
    }


    scanf("%d",&n);
    while(n--)
    {
         int M,N,xi,yi,i,j,xf,yf;
         int front = -1, rear = -1;
        char c;

    char *s=(char*)malloc(sizeof(char)*10000);



        scanf("%d %d",&M,&N);
         for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            distance[i][j]=0;
            status[i][j]=0;
            maze[i][j]=-1;
        }
    }



        for(i=1;i<=M;i++)
        {

            scanf("%s",s);
            for(j=1;j<=N;j++)
            {
                c=s[j-1];

                if(c=='S')
                {
                    maze[j][i] = 1;
                    xi = j;
                    yi= i;
                }
                if(c=='F')
                {
                    maze[j][i] = 1;
                    xf = j;
                    yf = i;
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
        free(s);

        if(xi==xf&&yi==yf)
            printf("0\n");
        else
        {
    EnQ(Q,xi,yi,&front,&rear);
    status[xi][yi]=waiting;
    distance[xi][yi]=0;
     int xtemp,ytemp,x,y;
    struct node z;
      i = 1;

    while(front<=rear)
    {
        z = DeQ(Q,&front,&rear);
        x = z.cordX;
        y = z.cordY;
        status[x][y] = visited;

         do
        {

        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {

            EnQ(Q,xtemp,ytemp,&front,&rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }


        xtemp = x + i;
        ytemp = y;
        i++;
//         printf("\n%d\n",maze[xtemp][ytemp]);

        if(maze[xtemp][ytemp]==-1)
            break;
        }while(xtemp<=N&&ytemp<=M&&i<=N*M);

        i = 1;
         do
        {


        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,&front,&rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
         xtemp = x - i;
        ytemp = y;
        i++;
        if(maze[xtemp][ytemp]==-1)
            break;
        }while(xtemp<=N&&ytemp<=M&&i<=N*M);
        i = 1;//printf("\nE reached \n");

         do
        {

        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,&front,&rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
        xtemp = x;
        ytemp = y+i;
        i++;
        if(maze[xtemp][ytemp]==-1)
            break;
        }while(xtemp<=N&&ytemp<=M&&i<=N*M);
        i = 1;
         do
        {

        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,&front,&rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
         xtemp = x;
        ytemp = y-i;
        i++;
        if(maze[xtemp][ytemp]==-1)
            break;
        }while(xtemp<=N&&ytemp<=M&&i<=N*M);
        i = 1;
         do
        {

        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,&front,&rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
        xtemp = x + i;
        ytemp = y + i;
        i++;
        if(maze[xtemp][ytemp]==-1)
            break;
        }while(xtemp<=N&&ytemp<=M&&i<=N*M);
        i = 1;
         do
        {

        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,&front,&rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
         xtemp = x + i;
        ytemp = y - i;
        i++;
        if(maze[xtemp][ytemp]==-1)
            break;
        }while(xtemp<=N&&ytemp<=M&&i<=N*M);
        i = 1;
         do
        {

        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,&front,&rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
         xtemp = x - i;
        ytemp = y + i;
        i++;
        if(maze[xtemp][ytemp]==-1)
            break;
        }while(xtemp<=N&&ytemp<=M&&i<=N*M);
        i = 1;
         do
        {

        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,&front,&rear);
            status[xtemp][ytemp]  = waiting;
            distance[xtemp][ytemp] = distance[x][y] + 1;
        }
        xtemp = x - i;
        ytemp = y - i;
        i++;
        if(maze[xtemp][ytemp]==-1)
            break;
        }while(xtemp<=N&&ytemp<=M&&i<=N*M);
        i = 1;


    }
    if(status[xf][yf]!=visited)
    printf("-1\n");
    else
    printf("%d\n",distance[xf][yf]);

  //  printf("%s",s);

        }
    }
}

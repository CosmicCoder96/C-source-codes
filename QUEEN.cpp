#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#define MAX 100001
#define initial 0
#define waiting 2
#define visited 3
using namespace std;
struct node{
     int cordX;
     int cordY;
};
void EnQ(struct node Q[], int x, int y, int * frontp,  int * rear)
{
    if(*frontp==-1)
        *frontp = *frontp + 1;
//    if(*rear>=MAX-1)
  //      return;
    *rear = *rear + 1;
    Q[*rear].cordX = x;
    Q[*rear].cordY = y;
   printf("\nEnqued %d %d\n",Q[*rear].cordX,Q[*rear].cordY);
    return;

}
struct node DeQ(struct node Q[], int * frontp,  int * rear)
{
    //if(*frontp==-1||*frontp>*rear)
    //    return ;
    struct node z = Q[*frontp];
    *frontp = * frontp + 1;
    printf("\Dequed\n");
    return z;
}
string s;

        int maze[1001][1001];
         int status[1001][1001];
         int distancep[1001][1001];
        struct node Q[1000000];
        //char s[1000000009];

int main()
{
    int n;
  /*  vector<vector<int>> maze;
     vector<vector<int>> status;
     vector<vector<int>>distancep;
     vector<struct node> Q;
     Q.resize(1001) ;
     maze.resize(1001,vector <int>(1001,0));
     status.resize(1001,vector <int>(1001,0));
     distancep.resize(1001,vector <int>(1001,0));*/


  /*   int maze[101][101]={0};
     int status[101][101]={0};
     int distancep[101][101]={0};
     */


    scanf("%d",&n);
    while(n--)
    {
         int M,N,xi,yi,i,j,xf,yf;
         int frontp = -1, rear = -1;
        char c;
        string s;

	//printf("0000");
        scanf("%d %d",&M,&N);



        for(i=1;i<=M;i++)
        {



            cin>>s;
             for(j=1;j<=N;j++)
            {
                c=s[j-1];
                //c==getchar();
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
        //printf("0000");
        if(xi==xf&&yi==yf)
            printf("0\n");
        else
        {
    EnQ(Q,xi,yi,&frontp,&rear);
    status[xi][yi]=waiting;
    distancep[xi][yi]=0;
     int xtemp,ytemp,x,y;
    struct node z;
     int i = 1;

    while(frontp<=rear)
    {
        z = DeQ(Q,&frontp,&rear);
        x = z.cordX;
        y = z.cordY;
        status[x][y] = visited;
        xtemp =x;
        ytemp=y;

         do
        {

//         printf("\n%d\n",maze[xtemp][ytemp]);


        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {

            EnQ(Q,xtemp,ytemp,&frontp,&rear);
            status[xtemp][ytemp]  = waiting;
            distancep[xtemp][ytemp] = distancep[x][y] + 1;
        }
xtemp = x + i;
        ytemp = y;
        i++;
        if(maze[xtemp][ytemp]==-1)
            break;




        }while(xtemp<=N&&ytemp<=M&&i<=N*M);
        i = 1;
         do
        {


        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,&frontp,&rear);
            status[xtemp][ytemp]  = waiting;
            distancep[xtemp][ytemp] = distancep[x][y] + 1;
        }
         xtemp = x - i;
        ytemp = y;
        i++;
        if(maze[xtemp][ytemp]==-1)
            break;
        }while(xtemp<=N&&ytemp<=M&&i<=N*M);
        i = 1;

         do
        {

        if(xtemp>=1&&ytemp>=1&&xtemp<=N&&ytemp<=M&&maze[xtemp][ytemp]==1&&status[xtemp][ytemp]==initial)
        {
            EnQ(Q,xtemp,ytemp,&frontp,&rear);
            status[xtemp][ytemp]  = waiting;
            distancep[xtemp][ytemp] = distancep[x][y] + 1;
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
            EnQ(Q,xtemp,ytemp,&frontp,&rear);
            status[xtemp][ytemp]  = waiting;
            distancep[xtemp][ytemp] = distancep[x][y] + 1;
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
            EnQ(Q,xtemp,ytemp,&frontp,&rear);
            status[xtemp][ytemp]  = waiting;
            distancep[xtemp][ytemp] = distancep[x][y] + 1;
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
            EnQ(Q,xtemp,ytemp,&frontp,&rear);
            status[xtemp][ytemp]  = waiting;
            distancep[xtemp][ytemp] = distancep[x][y] + 1;
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
            EnQ(Q,xtemp,ytemp,&frontp,&rear);
            status[xtemp][ytemp]  = waiting;
            distancep[xtemp][ytemp] = distancep[x][y] + 1;
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
            EnQ(Q,xtemp,ytemp,&frontp,&rear);
            status[xtemp][ytemp]  = waiting;
            distancep[xtemp][ytemp] = distancep[x][y] + 1;
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
    printf("%d\n",distancep[xf][yf]);

  //  printf("%s",s);

        }
    }
}

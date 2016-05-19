#include<stdio.h>
#define initial 0
#define waiting 1
#define visited 2
#define MAX 1000001
int Q[MAX],status[MAX]={initial},statusy[MAX]={initial},distance[MAX];
void EnQ(int Q[],int x,int *front,int *rear)
{
    if(*front==-1)
        *front =0;
    if(*rear==MAX-1)
       return;
    *rear = *rear +1;
    Q[*rear] = x;
    //printf("\nEnqued\n");
    return;
}
int DeQ(int Q[],int *front,int *rear)
{
    if(*front==-1||*front>*rear)
        return -1;
    int z = Q[*front];
    *front = *front + 1;
     //printf("\nDequed\n");
    return z;
}
void DFS( int n1, int m1, int n2, int m2,int * front, int * rear){
    EnQ(Q,n1*10+m1,front,rear);

    status[n1*10+m1]=waiting;
    distance[n1*10+m1] = 0;
    int fn1, fm1,nm;
while(*front<=*rear)
{
    nm=DeQ(Q,front,rear);
    n1 = nm/10;
    m1 = nm%10;
    status[n1*10+m1]=visited;
   // distance[fn1*10+fm1] =distance[n1*10+m1]+1;
    fn1 = n1 + 1;
    fm1 = m1 + 2;
    if(status[fn1*10+fm1]==initial&&fn1<=8&&fn1>=1&&fm1<=8&&fm1>=1){


        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;

    }

    fn1 = n1 + 1;
    fm1 = m1 - 2;
     if(status[fn1*10+fm1]==initial&&fn1<=8&&fn1>=1&&fm1<=8&&fm1>=1){
        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;
    }

    fn1 = n1 - 1;
    fm1 = m1 + 2;
     if(status[fn1*10+fm1]==initial&&fn1<=8&&fn1>=1&&fm1<=8&&fm1>=1){
        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;
    }
    fn1 = n1 - 1;
    fm1 = m1 - 2;
     if(status[fn1*10+fm1]==initial&&fn1<=8&&fn1>=1&&fm1<=8&&fm1>=1){

        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;
    }

    fn1 = n1 + 2;
    fm1 = m1 + 1;
     if(status[fn1*10+fm1]==initial&&fn1<=8&&fn1>=1&&fm1<=8&&fm1>=1){

        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;

    }
    fn1 = n1 + 2;
    fm1 = m1 - 1;
     if(status[fn1*10+fm1]==initial&&fn1<=8&&fn1>=1&&fm1<=8&&fm1>=1){


        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;
    }
    fn1 = n1 - 2;
    fm1 = m1 + 1;
     if(status[fn1*10+fm1]==initial&&fn1<=8&&fn1>=1&&fm1<=8&&fm1>=1){


        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;

    }


    fn1 = n1 - 2;
    fm1 = m1 - 1;
     if(status[fn1*10+fm1]==initial&&fn1<=8&&fn1>=1&&fm1<=8&&fm1>=1){


        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;


    }

}
printf("%d\n",distance[n2*10+m2]);
}

int main()
{
    int n,i;
    scanf("%d",&n);
    while(n--){
    int n1=0,n2=0,m1,m2,front = -1, rear = -1;
    char c1[4];
    char c2[4];
    scanf("%s %s",c1,c2);



    m1 = c1[1] - '0';
    m2 = c2[1] - '0';

    if(c1[0]=='a')
        n1 = 1;
     if(c1[0]=='b')
        n1 = 2;
     if(c1[0]=='c')
        n1 = 3;
     if(c1[0]=='d')
        n1 = 4;
     if(c1[0]=='e')
        n1 = 5;
     if(c1[0]=='f')
        n1 = 6;
     if(c1[0]=='g')
        n1 = 7;
     if(c1[0]=='h')
        n1 = 8;
     if(c2[0]=='a')
        n2 = 1;
     if(c2[0]=='b')
        n2 = 2;
     if(c2[0]=='c')
        n2 = 3;
     if(c2[0]=='d')
        n2 = 4;
     if(c2[0]=='e')
        n2 = 5;
     if(c2[0]=='f')
        n2 = 6;
     if(c2[0]=='g')
        n2 = 7;
     if(c2[0]=='h')
        n2 = 8;
       // printf("%d %d",n2,m2);
  DFS(n1,m1,n2,m2,&front,&rear);
  for(i=0;i<100;i++)
  {
      Q[i]=0;
      status[i]=0;
      distance[i]=0;
  }
    }
    return 0;

}

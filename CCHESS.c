#include<stdio.h>
#define initial 0
#define waiting 1
#define visited 2
#define MAX 1000001
#define NIL -1
int Q[MAX],status[MAX]={initial},statusy[MAX]={initial},distance[MAX],predecessor[MAX],sum[MAX];
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
     sum[n1*10+m1]=0;
    int fn1, fm1,nm,summ=0,minsum=100000,finalsum=0,sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,sum7=0,sum8=0;
while(*front<=*rear)
{
    nm=DeQ(Q,front,rear);
    n1 = nm/10;
    m1 = nm%10;
    status[n1*10+m1]=visited;
    summ = sum[n1*10+m1];
   distance[fn1*10+fm1] =distance[n1*10+m1]+1;

    fn1 = n1 + 1;
    fm1 = m1 + 2;
    if(status[fn1*10+fm1]==initial&&fn1<=7&&fn1>=0&&fm1<=7&&fm1>=0){


        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;
        predecessor[fn1*10+fm1]=n1*10+m1;
        summ+=(n1*fn1+ m1*fm1);
        sum[fn1*10+fm1]=sum;

    }

    fn1 = n1 + 1;
    fm1 = m1 - 2;
     if(status[fn1*10+fm1]==initial&&fn1<=7&&fn1>=0&&fm1<=7&&fm1>=0){
        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;
         predecessor[fn1*10+fm1]=n1*10+m1;
         summ+=(n1*fn1+ m1*fm1);
        sum[fn1*10+fm1]=sum;
    }

    fn1 = n1 - 1;
    fm1 = m1 + 2;
     if(status[fn1*10+fm1]==initial&&fn1<=7&&fn1>=0&&fm1<=7&&fm1>=0){
        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;
         predecessor[fn1*10+fm1]=n1*10+m1;
        summ+=(n1*fn1+ m1*fm1);
        sum[fn1*10+fm1]=sum;
    }
    fn1 = n1 - 1;
    fm1 = m1 - 2;
     if(status[fn1*10+fm1]==initial&&fn1<=7&&fn1>=0&&fm1<=7&&fm1>=0){

        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;
         predecessor[fn1*10+fm1]=n1*10+m1;
         summ+=(n1*fn1+ m1*fm1);
        sum[fn1*10+fm1]=sum;
    }

    fn1 = n1 + 2;
    fm1 = m1 + 1;
     if(status[fn1*10+fm1]==initial&&fn1<=7&&fn1>=0&&fm1<=7&&fm1>=0){

        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;
         predecessor[fn1*10+fm1]=n1*10+m1;
        summ+=(n1*fn1+ m1*fm1);
        sum[fn1*10+fm1]=sum;
    }
    fn1 = n1 + 2;
    fm1 = m1 - 1;
     if(status[fn1*10+fm1]==initial&&fn1<=7&&fn1>=0&&fm1<=7&&fm1>=0){


        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;
         predecessor[fn1*10+fm1]=n1*10+m1;
         summ+=(n1*fn1+ m1*fm1);
        sum[fn1*10+fm1]=sum;
    }
    fn1 = n1 - 2;
    fm1 = m1 + 1;
     if(status[fn1*10+fm1]==initial&&fn1<=7&&fn1>=0&&fm1<=7&&fm1>=0){


        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;
         predecessor[fn1*10+fm1]=n1*10+m1;
         summ+=(n1*fn1+ m1*fm1);
        sum[fn1*10+fm1]=sum;

    }


    fn1 = n1 - 2;
    fm1 = m1 - 1;
     if(status[fn1*10+fm1]==initial&&fn1<=7&&fn1>=0&&fm1<=7&&fm1>=0){


        EnQ(Q,fn1*10+fm1,front,rear);
        status[fn1*10 +fm1] = waiting;
        distance[fn1*10+fm1] = distance[n1*10+m1] + 1;
         predecessor[fn1*10+fm1]=n1*10+m1;
         summ+=(n1*fn1+ m1*fm1);
        sum[fn1*10+fm1]=sum;

    }

      //  finalsum=sum1+sum2+sum3+sum4+sum5+sum6+sum7+sum8;
        if(minsum>summ)
            minsum=summ;

    //sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,sum7=0,sum8=0;



}
printf("%d %d\n",distance[n2*10+m2],minsum);

}

int main()
{
    int n,i;
    int path[1000];
    scanf("%d",&n);
    while(n--){
    int n1=0,n2=0,m1,m2,front = -1, rear = -1,sum=0,count=0,u,v;
    scanf("%d %d %d %d",&n1,&m1,&n2,&m2);
  DFS(n1,m1,n2,m2,&front,&rear);
  v=n2*10+m2;
  while(v!=NIL)
		{
			count++;
			path[count]=v;
			u = predecessor[v];
			v = u;
		}

		//printf("Shortest Path is : ");
		for(i=count; i>1; i--)
        {
            printf("%d->",path[i]);
            sum = sum +(path[i]/10)*(path[i-1]/10)+(path[i]%10)*(path[i-1]%10);

        }
        printf("\n%d",sum);


		printf("\n");
  for(i=0;i<100;i++)
  {
      Q[i]=0;
      status[i]=0;
      distance[i]=0;

  }
    }
    return 0;

}

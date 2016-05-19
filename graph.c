#include<stdio.h>
#include<string.h>
#define MAX 100
#define initial 0
#define waiting 1
#define visited 2
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
        return;
    int z = Q[*front];
    *front = *front + 1;
   //  printf("\nDequed\n");
    return z;
}
int compare(char *s1, char* s2)
{
    int l1 = strlen(s1);
     int l2 = strlen(s2);
     int i,j;
    for(i=0;i<l1;i++)
    {
        for(j=0;j<l2;j++)
        {
            //printf("hello");
            if(s1[i]==s2[j])
                return 1;
        }
    }
    return 0;
}
void BFS(int v,int n2,int n, int Q[],int adj[][MAX],int state[], int *front,int *rear)
{
    int i;
    EnQ(Q,v,front,rear);
    //printf("0000\n");
    state[v] = waiting;
   // printf("front = %d rear = %d\n",*front,*rear);
    while(*front<=*rear)
    {
        v = DeQ(Q,front,rear);
        state[v] = visited;
      //  printf("1111\n");
        for(i=0;i<n;i++)
        {
            if(adj[v][i]==1&&state[i]==initial)
            {
                EnQ(Q,i,front,rear);
                state[i] = waiting;
            }
        }

    }
    if(state[n2]==visited)
        printf("Yes");
    else
        printf("No");

}

int main()
{
    int adj[MAX][MAX],state[MAX],n,i,j,c,v,n1=-1,n2=-1,Q[MAX],front =-1,rear=-1;
    //printf("0000");
    scanf("%d",&n);
    char s[n][MAX],s1[MAX],s2[MAX];
    for(i=0;i<n;i++)
        scanf("%s",s[i]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            c = compare(s[i],s[j]);
            if(c==1){
                adj[i][j]=1;
                adj[j][i]=1;
            }

        }
    }
    scanf("%s %s",s1,s2);
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i],s1)==0)
            n1 =i;
        if(strcmp(s[i],s2)==0)
            n2 = i;
        //printf("%d %d",n1,n2);
    }
    for(v=0;v<n;v++)
        state[v]=0;
    BFS( n1,n2,n,Q,adj, state, &front,&rear);



}

//common char connected
//test case s1 and s2;

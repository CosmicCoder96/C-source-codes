#include<stdio.h>
#include<stdlib.h>
#define TEMP 0
#define PERM 1
#define infinity 1000000
#define MAX 10000
#define NIL -1
void Djikstras(int n, int **,int status[], int predecessor[],int pathLength[],int s);
int min_temp(int status[],int pathLength[],int n );
int main(){
int t;
scanf("%d",&t);
while(t--)
{
    int v , k , a, b, c,n,i,j,source,destination;
    scanf("%d %d",&v,&k);
   int ** adj = (int**)malloc(sizeof(int*)*(v+1));
   for(i=0;i<=v;i++)
        adj[i] = (int*)malloc(sizeof(int)*(v+1));
    n = v+1;
   // int adj[v+1][v+1];
    for(i=0;i<=v;i++)
    {
        for(j=0;j<=v;j++)
            adj[i][j]=0;
    }
    int * status = (int*)malloc(sizeof(int)*(v+1));
    int * predecessor = (int*)malloc(sizeof(int)*(v+1));
    int * pathLength = (int*)malloc(sizeof(int)*(v+1));
    for(i=0;i<k;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        adj[a][b]=c;
    }
   // printf("toodles");
    scanf("%d %d",&source,&destination);

   Djikstras(n,adj,status,predecessor,pathLength,source);
    if(pathLength[destination]!=infinity)
        printf("%d\n",pathLength[destination]);
    else
        printf("NO\n");
    free(adj);
    free(pathLength);
    free(status);
    free(predecessor);
}
}
void Djikstras(int n, int** adj,int status[], int predecessor[],int pathLength[],int s)
{
    int i,current;


	for(i=0; i<n; i++)
	{
		predecessor[i] =  NIL;
		pathLength[i] = infinity;
		status[i] = TEMP;
	}

	pathLength[s] = 0;
	while(1)
	{


		current = min_temp( status,pathLength,n);
	//	printf("\n Current : %d \n",current);


		if( current == NIL )
		{

			return;
		}

		status[current] = PERM;

		for(i=0;i<n;i++)
		{
		//    printf("\nadj :%d i: %d\n",adj[current][i],i);

			if ( adj[current][i] !=0 && status[i] == TEMP )
			{
			//    printf("\nadj%d i : %d\n",adj[current][i],i);

				if( pathLength[current] + adj[current][i] < pathLength[i] )
				{

					predecessor[i] = current;
					pathLength[i] = pathLength[current] + adj[current][i];
				//	printf("\nhello\n");

				}

			}
		}
	}

}
int min_temp(int status[],int pathLength[],int n )
{
	int i;
	int min = infinity;
	int k = NIL;
	for(i=0;i<n;i++)
	{
		if(status[i] == TEMP && pathLength[i] < min)
		{
			min = pathLength[i];
			k = i;
		}
	}
	return k;
}

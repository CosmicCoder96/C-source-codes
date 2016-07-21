#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
struct node
{
    long long int data;
    long long int rank;
    struct node* parent;
};

struct node* MakeSet( int data);
struct node* Union(struct node* n1, struct node* n2);
struct node* findSet(struct node* n);
struct node* a[MAX];
int y[MAX]={0};

int main()
{

    struct node* temp;
    int c,x,x1,x2,N,M,i,u,v,y1,j,max=1,min=1,y2;
    scanf("%d %d",&N,&M);
    for(i=0;i<=N;i++)
        {
        a[i]=MakeSet(i);
        y[i]=1;

    }
    x=N;
    for(i=0;i<M;i++)
    {
        scanf("%d %d",&u,&v);

         Union(a[u],a[v]);
    for(j=1;j<=N;j++)
    {
        x=findSet(a[j])->data;
        if(y[x]>maxm)
            maxm=y[x];
        if(y[x]<minm)
            minm=y[x];

         //   printf("%d ",y[j]);
    }
        // printf("\nparent %d\n",findSet(a[u])->data);
         //std::sort(y,y+(N+1));
      //   for(j=0;j<=N;j++)
        //    printf(" %d",y[j]);

        printf("%d\n",maxm-minm);
    }

}
struct node* MakeSet( int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->rank =0;
    temp->parent = temp;
    return temp;
};
struct node* Union(struct node* n1, struct node* n2)
{
    /* The two nodes n1 and n2 just given need not be the representative nodes of the tree or set
    and therefore we need to find their representative nodes before proceeding forward */
    struct node* parent1 = findSet(n1);
    struct node* parent2 = findSet(n2);
    if(parent1->data==parent2->data)
        return parent1;

        y[findSet(n1)->data]+=y[findSet(n2)->data];
        parent2->parent = parent1;
        //increase the rank only if the original ranks are equal

        return parent1;



};
struct node* findSet(struct node* n)
{
    //by using this we will effectively be applying path compression on the tree as well.
    struct node* temp = n->parent;
    if(temp==n)
    return temp;

   /* n->parent = findSet(n->parent);
    return n->parent;*/
    while(temp!=temp->parent)
    {

        temp=temp->parent;
    }
            n->parent =temp;
    return n->parent;


};

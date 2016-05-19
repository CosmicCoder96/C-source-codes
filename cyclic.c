#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
struct node{
int data;
int rank;
struct node *parent;
};
struct node* MakeSet(int x);
void Union(struct node* n1, struct node* n2);
struct node* findSet(struct node* n);
int main()
{
    struct node *Q[MAX];
    int u,v,i,x,flag=0,n;
    printf("Enter the number of vertices:\n");

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        Q[x] = MakeSet(x);

    }
    printf("\nEnter the edges:(-1 -1 to terminate)\n:");
    while(1)
    {
     scanf("%d %d",&u,&v);
     if(u==-1&&v==-1)
        break;
     if(findSet(Q[u])==findSet(Q[v]))
        flag=1;
     Union(Q[u],Q[v]);
    }
    if(flag==1)
        printf("\nIt's a cyclic graph\n");
    else
        printf("\nThere are no cycles in the given graph");
    return 0;
}
struct node* MakeSet(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->rank = 0;
    temp->parent = temp;
    return temp;
};
void Union(struct node* n1, struct node* n2)
{
struct node * p1 = findSet(n1);
struct node* p2 = findSet(n2);
if(p1->data==p2->data)
    return;
if(p1->rank>=p2->rank){
    p2->parent=p1;
if(p1->rank==p2->rank)
    p1->rank=p1->rank + 1;

}
else
    p1->parent=p2;
}

struct node* findSet(struct node* n)
{
    if(n->parent==n)
        return n;
    else
    {
        n->parent=findSet(n->parent);
        return n->parent;
    }
}

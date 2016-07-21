#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAX 100000
struct node
{
    long long int data;
    long long int rank;
    struct node* parent;
};
//union by rank says that make the guy who has the higher rank, the parent and the one with the lower rank the child.
//rank of non root nodes doesn't matter
//after union of same rank trees , rank gets increased by one of the new root.
/*path compression means that make all the parent nodes of trees point to the root so that at max ,
the depth is reduced to just 1 so it will take lesser time to find the representative element*/
/* Time and space Complexities
    n elements -> space = O(n) m operations -> O(m)*/
struct node* MakeSet(long long int data);
struct node* Union(struct node* n1, struct node* n2);
struct node* findSet(struct node* n);
struct node* a[MAX];
int y[MAX];

int main()
{

    struct node* temp;
    long long int c,x,x1,x2,N,M,i,u,v;
    scanf("%lld %lld",&N,&M);
    for(i=0;i<=N;i++)
        a[i]=MakeSet(i);
    x=N;
    for(i=0;i<M;i++)
    {
        scanf("%lld %lld",&u,&v);
         Union(a[u],a[v]);
         y[a[findset[u]]]++;
    }
    printf("%lld",x);
}
struct node* MakeSet(long long int data)
{
    struct node* temp = malloc(sizeof(struct node));
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
    if(parent1->rank>=parent2->rank)
    {
        parent2->parent = parent1;
        //increase the rank only if the original ranks are equal
        if(parent1->rank==parent2->rank)
            parent1->rank= parent1->rank + 1;

        return parent1;

    }
    else
        parent1->parent = parent2;
        return parent2;
};
struct node* findSet(struct node* n)
{
    //by using this we will effectively be applying path compression on the tree as well.
    struct node* temp = n->parent;
    if(temp==n)
    return temp;

    n->parent = findSet(n->parent);
    return n->parent;

};

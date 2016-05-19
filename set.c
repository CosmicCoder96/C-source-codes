#include<stdio.h>
#define MAX 1000
struct node
{
    int data;
    int rank;
    struct node* parent;
};
//union by rank says that make the guy who has the higher rank, the parent and the one with the lower rank the child.
//rank of non root nodes doesn't matter
//after union of same rank trees , rank gets increased by one of the new root.
/*path compression means that make all the parent nodes of trees point to the root so that at max ,
the depth is reduced to just 1 so it will take lesser time to find the representative element*/
/* Time and space Complexities
    n elements -> space = O(n) m operations -> O(m)*/
struct node* MakeSet(int data);
struct node* Union(struct node* n1, struct node* n2);
struct node* findSet(struct node* n);

int main()
{
    struct node* a[MAX];
    struct node* temp;
    int c,x,x1,x2;
    while(1){
    printf("---------|||||----------\n");
    printf("1.Make Set");
    printf("\n2.Find Set");
    printf("\n3.Union");
    printf("\n4.exit\n");
    printf("---------|||||----------\n\n");
    scanf("%d",&c);
    if(c==1)
    {
    printf("\nEnter the value\n");
    scanf("%d",&x);
    a[x] = MakeSet(x);


    }
    else if(c==2)
    {
        printf("\nEnter the value\n");
    scanf("%d",&x);
    temp = findSet(a[x]);
    printf("\n%d\n",temp->data);

    }
    else if(c==3)
    {
        printf("\nEnter the two elements\n");
        scanf("%d %d",&x1,&x2);
        temp = Union(findSet(a[x1]),findSet(a[x2]));
    }


    }
}
struct node* MakeSet(int data)
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

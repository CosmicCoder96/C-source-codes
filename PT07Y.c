#include<stdio.h>
#define MAX 100000
struct node
{
    int data;
    int rank;
    struct node* parent;
};

    n elements -> space = O(n) m operations -> O(m)*/
struct node* MakeSet(int data);
struct node* Union(struct node* n1, struct node* n2);
struct node* findSet(struct node* n);

int main()
{
    struct node* a[MAX];
    struct node* temp;
    int c,x,x1,x2,N,M,i,u,v;
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++)
        a[i]=MakeSet(i);
    for(i=0;i<M;i++)
    {
        scanf("%d %d",&u,&v);
        if(v<u)
        {
            x2=u;
            u=v;
            v=u;
        }



        if(findSet(a[u])->data!=findSet(a[v])->data)
        {
           // printf("\n%d %d\n",findSet(a[u])->data,findSet(a[v])->data);
            Union(a[u],a[v]);
          //  printf("\nlater %d %d\n",findSet(a[u])->data,findSet(a[v])->data);
            //printf("union\n");
        }

        else{
            printf("NO");
            break;
        }



    }
    if(i==M)
        printf("YES");

   // a[x] = MakeSet(x);



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

    n2->parent = n1;
};
struct node* findSet(struct node* n)
{

    struct node* temp = n->parent;
   // if(temp==n)
    return temp;




};

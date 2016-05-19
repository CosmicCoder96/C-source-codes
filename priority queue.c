#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int priority;
};
void print(struct node a[], int n);
void heap_sort(struct node a[],int n)
{
    int i,j;
    struct node sorted[n];
    for(i=n,j=0;i>=0;i--,j++)
    {
        MinHeapify(a,i);
        sorted[j]=a[0];
        a[0]=a[i-1];



    }
    for(i=0;i<n;i++)
       a[i]=sorted[i];


}
void MinHeapify(struct node a[], int n)
{
    int temp,left,right,i;
    struct node val;


    for(i=n/2 -1;i>=0;i--)
    {
    temp=i;
    left = 2*i + 1;
    right = 2*i+2;
    if(left<n&&a[temp].priority>a[left].priority)
    temp = left;
    if(right<n&&a[temp].priority>a[right].priority)
    temp = right;
    if(temp!=i)
        {
        val = a[i];
        a[i]=a[temp];
        a[temp]=val;
        }

    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    struct node  Q[n];

    for(i=0;i<n;i++)
        scanf("%d %d",&Q[i].data,&Q[i].priority);
    heap_sort(Q,n);
    print(Q,n);



}
void print(struct node a[],int n)
{
    int i;
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d %d\n",a[i].data,a[i].priority);
}

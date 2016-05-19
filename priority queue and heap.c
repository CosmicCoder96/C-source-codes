#include<stdio.h>
#include<stdlib.h>
void print(int a[], int n);
void heap_sort(int a[],int n)
{
    int sorted[n],i,j;
    for(i=n,j=0;i>=0;i--,j++)
    {
        MinHeapify(a,i);
        sorted[j]=a[0];
        a[0]=a[i-1];



    }
    for(i=0;i<n;i++)
        a[i]=sorted[i];
}
void MinHeapify(int a[], int n)
{
    int temp,left,right,val,i;


    for(i=n/2 -1;i>=0;i--)
    {
    temp=i;
    left = 2*i + 1;
    right = 2*i+2;
    if(left<n&&a[temp]>a[left])
    temp = left;
    if(right<n&&a[temp]>a[right])
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
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    heap_sort(a,n);
    print(a,n);


}
void print(int a[],int n)
{
    int i;

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

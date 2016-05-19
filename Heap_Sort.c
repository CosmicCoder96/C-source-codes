#include<stdio.h>
void Heap_Sort(int a[], int n);
void Min_Heapify(int a[],int n);
void display(int a[],int n);
int main()
{
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    a[0]=-1;
    printf("The array entered is : ");

    display(a,n);
    Heap_Sort(a,n);
    printf("The sorted array is : ");
    display(a,n);

}
void display(int a[], int n)
{
    int i =0;
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);

    printf("\n");
    return;
}
void Heap_Sort(int a[], int n)
{
    int sorted[n], i, j , temp;
    sorted[0]=-1;
    for(i=n+1,j=1;i>=1;i--,j++)
    {
        Min_Heapify(a,i);
        sorted[j] = a[1];
        a[1]=a[i-1];

    }
    for(i=1;i<=n;i++)
        a[i]=sorted[i];

}
void Min_Heapify(int a[],int n)
{
    int i,left,right,temp,val;
    for(i=n/2;i>=1;i--)
    {


    temp = i;
    left = 2*i;
    right = 2*i +1;
    if(left<n&&a[left]<a[temp])
        temp = left;
    if(right<n&&a[right]<a[temp])
        temp = right;
    if(temp!=i)
    {
        val = a[i];
        a[i]=a[temp];
        a[temp]=val;
        Min_Heapify(a,n);
    }
    }
}

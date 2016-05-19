#include<stdio.h>
// Quick Sort
void quick_sort(int a[],int n);
int main()
{
    int n,i;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements of the array:\n");
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    quick_sort(a,0,n-1);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
void quick_sort(int a[], int start, int end)
{
    if(start<end)
        {
            int partitionIndex = partition(a,start,end);
            quick_sort(a,start,partitionIndex-1);
            quicksort(a,partitionIndex+1,end);
        }
}
void partition(int a[], int start, int end)
{
    int pivot = a[end];
    for(i=start,i<n;i++)
    {
        if(a[i]<=pivot)
            swap(a[i])
    }
}

#include<stdio.h>
// Insertion Sort
void selection_sort(int a[],int n);
int main()
{
    int n,i;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements of the array:\n");
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    selection_sort(a,n);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);


}
void selection_sort(int a[], int n)
{
    int i,j,imin,temp;
    for(i=0;i<n-1;i++)
    {
        imin = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[imin])
                imin = j;

        }
         temp = a[i];
         a[i]= a[imin];
         a[imin]=temp;
    }
}

#include<stdio.h>
//Bubble Sort
void bubble_sort(int a[],int n);
int main()
{
    int n,i;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements of the array:\n");
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    bubble_sort(a,n);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
void bubble_sort(int a[], int n)
{
    int i,j,flag,temp;
    for(i=0;i<n-1;i++)
    {
        flag = 0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j]=a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(flag ==0)
            break;
    }

}

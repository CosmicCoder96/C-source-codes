#include<stdio.h>
#include<stdlib.h>
void msort(int a[], int left , int right);
void merge(int a[], int left, int mid, int right);

int main()
{
	int n,i;
	printf("Enter the number of elements in array : \n");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the elements of the array : \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	msort(a,0,n-1);
	printf("\nThe sorted array is : \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void msort(int a[],int left, int right)
{
	int mid;
	if(left<right)
	{

		mid = (left + right)/2;
		msort(a,left,mid);
		msort(a,mid+1,right);
		merge(a,left,mid,right);
	}
	else
		return;
}
void merge(int a[], int left,int mid, int right)
{
	int temp[right-left+1];
	int pos =0, lpos = left, rpos = mid+1,i;
	while(lpos<=mid &&  rpos<=right)
	{
		if(a[lpos]<a[rpos])
			temp[pos++]=a[lpos++];
		else
			temp[pos++]=a[rpos++];
	}
	while(lpos<=mid)
		temp[pos++] = a[lpos++];
	while(rpos<=right)
		temp[pos++]  = a[rpos++];
	for(i=0;i<pos;i++)
		a[i+left] = temp[i];
	return;
}


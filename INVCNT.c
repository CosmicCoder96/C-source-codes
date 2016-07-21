#include<stdio.h>


long long int merge(int a[],int temp[],int left, int mid, int right)
{
    int i,j,k;
	long long int count=0;
	i=left;
	j=mid;
	k=left;
	while(i<=mid-1 && j<=right)
	{
		if(a[i]<=a[j])
			temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
			count+=(mid-i);
		}
	}
	while (i<=mid-1)
		temp[k++]=a[i++];
	while(j<=right)
		temp[k++]=a[j++];
	for(i=left;i<=right;i++)
		a[i]=temp[i];
	return count;

}
long long int merge_sort(int a[],int temp[],int left,int right)
{
    int mid;
    long long int count=0;
    if(left<right)
    {
        mid = (left+right)/2;
        count=merge_sort(a,temp,left,mid);
		count+=merge_sort(a,temp,mid+1,right);
		count+=merge(a,temp,left,mid+1,right);
    }
    return count;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
            int a[n],temp[n],i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        printf("%lld\n",merge_sort(a,temp,0,n-1));

    }
}

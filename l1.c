#include <stdio.h>
#include <stdlib.h>



void count();
void maximum_minimum();
void kthlargest();
void creation();
int array[1000];
int l;
void insertion(int input,int k);
void deletion(int input);
void displaArray();
void search(int input);

int main()
{
	int c;
	int no;


	creation();
	int x,y;
	printf("Press the following for availing these choices:\n");

	printf("1.insertion\n2.deletion \n3.Traversal \n4.Searching \n5.Counting no. of occurences \n6.Finding maximum and minimum \n7.Finding kih largest inputent\n8.Quit\n");
	char an;
	scanf("%d",&c);

	while(1==1)
	{
		switch(c)
		{
			case 1:
				printf("Enter the elemnts for insertion, maximum elements in array = 1000");
				scanf("%d",&x);
				printf("Enter index:");
				scanf("%d",&y);
				insertion(x,y);
				break;
			case 2:
				printf("Enter inputent to deletion:");
				scanf("%d",&x);
				deletion(x);
				break;
			case 3:
				displaArray();
				break;
			case 4:
				printf("Enter inputent to search:\n");
				scanf("%d",&x);
				search(x);
				break;
			case 5:

				count();
				break;
			case 6:
				maximum_minimum();
				break;
			case 7:
				kthlargest();
				break;
			case 8:
				exit(0);
				break;
			default:
				printf("Incorrect choice.\n");
		}
		printf("Press E to exit the program or C to continue:\n");
		scanf(" %c",&an);
		if(an=='e' || an=='E')
			break;
		printf("1.insertion\n2.deletion \n3.Traversal \n4.Search The array for an element \n5.Counting no. of occurences of each value \n6.Finding maximum and minimum \n7.Finding kih largest inputent\n8.Quit\n");
		scanf("%d",&c);
	}
	return 0;
}

void insertion(int input,int k)  //Working
{
	int i;
	if(l>=1000)
	{
		printf("Out of bounds.\n");
	}

	else
	{
		for(i=l-1;i>=k;i--)
		{
			array[i+1]=array[i];
		}
		array[k]=input;
		l++;
	}
}

void deletion(int input)
{
	int i;int flag=0;
	for(i=0;i<l;i++)
	{
		if(array[i]==input){
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("inputent not found..\n");
	else
	{
		int j;
		for(j=i;j<l-1;j++)
		{
			array[j]=array[j+1];
		}
		l--;
	}
}

void displaArray()  //Working
{
	int i;
	printf("The inputents of the array is:\n");
	for(i=0;i<l;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}


void search(int input)  //Working
{
	int flag=0;
	int i;
	for(i=0;i<l;i++)
	{
		if(array[i]==input)
		{
			printf("inputent found at index %d.\n",i);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("inputent not found.\n");
	}
}




void count()
{
	int b[l];
	int i,j,temp;
	for(i=0;i<l;i++)
		b[i]=array[i];
	//int j;
	for(i=0;i<l-1;i++)
	{
		for(j=0;j<l-i-1;j++)
		{
			if(b[j]<b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	int count=1;

	for(i=1;i<=l;i++)
	{
		if (b[i]==b[i-1])
		{
			count++;
		}
		else
		{
			printf("%d occurs %d times.\n", b[i-1],count);
			count=1;
		}

	}

}

void maximum_minimum() //Working
{
	int min,max;
	//int mi[l],int marray[l];
	min=max=array[0];
	int i;
	for(i=0;i<l;i++)
	{
		if(array[i] < min)
		{
			min=array[i];
		}
		if (array[i]> max)
		{
			max=array[i];
		}
	}
	printf("Maximum value is %d and occurs at ", max);
	for(i=0;i<l;i++)
	{
		if (array[i]==max)
		{
			printf("%d ", i);
		}
	}
	printf(".\n");

	printf("Minimum value is %d and occurs at ", min);
	for(i=0;i<l;i++)
	{
		if (array[i]==min)
		{
			printf("%d ", i);
		}
	}
	printf(".\n");

}


void kthlargest()  //working
{
	int b[l],i;
	printf("Enter the value of k\n");
	int ki,temp;
	scanf("%d",&ki);
	for(i=0;i<l;i++)
		b[i]=array[i];
	int j;
	for(i=0;i<l-1;i++)
	{
		for(j=0;j<l-i-1;j++)
		{
			if(b[j]<b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	int c[l];
	c[0]=b[0];
	int k=1;
	for(i=0;i<l-1;i++)
	{
		if(b[i]!=b[i+1])
		{
			c[k++]=b[i+1];
		}

	}

	printf("The %d th largest element is %d.\n",ki,c[ki-1]);
}





void creation()
{
	int i;
	printf("Enter the number of elements\n");
	scanf("%d",&l);
	printf("Enter the elements\n");
	for (i = 0; i < l; ++i)
	{
		scanf("%d",&array[i]);
	}
}

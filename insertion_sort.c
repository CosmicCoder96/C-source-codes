#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* insert(struct node* root, int value);
struct node* deleten(struct node*root, int value);
int depth(struct node* root, struct node* value, int d);
struct node* MinEp(struct node* root);
void inorder(struct node*root, int dm,struct node* rooti, struct node** roots, int* k)
{
	if(root==NULL)
		return;
	int x=depth(rooti,root,0);

//	printf("%d ",x);
	if(x>dm){
	roots[*k]=root;
	*k = *k + 1;
	}


	inorder(root->left,dm,rooti,roots,k);
	inorder(root->right,dm,rooti,roots,k);
}
void inorder2(struct node*root)
{
	if(root==NULL)
		return;

	inorder2(root->left);
	printf("%d ",root->data);
	inorder2(root->right);
}
int main()
{
	struct node* root = NULL;
	struct node*roots[100000];

	int n,i,k,x,z;
	for(i=0;i<100000;i++)
		roots[i]=NULL;
	scanf("%d %d",&n,&z);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		root = insert(root,x);
	}
	k=0;
	inorder(root,z,root,roots,&k);
	for(i=0;i<k;i++){
		if(roots[i]!=NULL)
		root = deleten(root,roots[i]->data);

	}
	inorder2(root);
	printf("\n");
	//root = deleten(root, 24);
//	printf("\n%d\n",depth(root,5,0));


}

struct node* insert(struct node* root, int value)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data=value;
	if(root==NULL)
	{
		temp->left=NULL;
		temp->right=NULL;
		root = temp;
		return root;
	}
	if(root->data<value)
		root->right = insert(root->right,value);
	else
		root->left=insert(root->left,value);
	return root;

}
struct node* deleten(struct node*root, int value)
{
	struct node* temp;
//	printf("delete");
	if(root==NULL)
		return NULL;
	if(root->data>value)
		root->left=deleten(root->left,value);
	else if (root->data<value)
		root->right=deleten(root->right,value);
	else
	{
		if(root->left==NULL&&root->right==NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->left==NULL)
		{
			temp = root;
			root=root->right;
			free(temp);
			return root;
		}
		else if(root->right==NULL)
		{
			temp = root;
			root=root->left;
			free(temp);
			return root;
		}
		else
		{
			temp = MinEp(root->right);
			root->data = temp->data;
			root->right = deleten(root->right,temp->data);
			return root;
		}
	}
	return root;
}

struct node* MinEp(struct node*root)
{
	if(root==NULL)
		return root;
	while(root->left!=NULL)
		root=root->left;
	return root;
}

int depth(struct node* root,struct node*  value, int d){
	if(root==NULL)
		return 0;
	if(root==value)
		return d;

	int d2 = depth(root->left,value,d+1);
	if(d2!=0)
		return d2;
	int d3= depth(root->right,value,d+1);
	return d3;
}


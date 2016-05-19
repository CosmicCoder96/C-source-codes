#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

struct node {
    struct  node* left;
    struct node* right;
    int data;
};


struct node* DeQ(struct node ** Q,int* front, int *rear);
struct node* insert(struct node* root, int x);
struct node* deleten(struct node* root, int value);
struct node* minEP(struct node*root);
void preorder(struct node* root);
void inorder(struct node*root);
void postorder(struct node*root);
void BFT(struct node* root);
void EnQ(struct node** Q,struct node* x,int* front, int *rear);
int minE(struct node*root);
int maxE(struct node* root);
int height(struct node*root);
int max(int a, int b);
int check(struct node* root);
int lesser(struct node* root,int a);
int greater(struct node* root,int a);
int level(struct node* root, int value, int level);
int isQempty(int*front,int*rear);
int SumOfLeaves(struct node* root, int * sum);
int LCA(struct node* root, int n1, int n2);

int main()
{
    int n,k,isBST,del,sum=0,t1,t2;
    struct node* root = NULL;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&k);
       root= insert(root,k);
    }
    printf("\nMin Element: %d\n",minE(root));
    printf("Max Element: %d\n",maxE(root));
    printf("Height of tree: %d\n",height(root));
    printf("Preorder : ");
    preorder(root);
    printf("\n");
    printf("Inorder : ");
    inorder(root);
    printf("\n");
    printf("Postorder : ");
    postorder(root);
    printf("\n");
    printf("Breadth First or level order Traversal : ");
    BFT(root);
    printf("\n");
    isBST = check(root);
    if(isBST==1)
    printf("Binary Search tree?? : Yes\n" );
    else
    printf("Binary Search tree?? : No\n" );
    printf("Sum Of Leaves : %d\n",SumOfLeaves(root,&sum));
    printf("Enter the element to be deleted : ");
    scanf("%d",&del);
    root = deleten(root,del);
    printf("\nThe new tree is : ");
    BFT(root);
    printf("\n");
    printf("Enter the node whose level you wish to find :");
    scanf("%d",&del);
    printf("\nThe level is : %d \n", level(root,del,1));
    printf("Enter the nodes for which you wish to find LCA : ");
    scanf("%d %d",&t1,&t2);
    printf("The lowest common ancestor is : %d\n",LCA(root,t1,t2) );





}
int LCA(struct node* root, int n1, int n2)
{
    if(root==NULL||root->data==n1||root->data==n2)
        return -1;
    else if(root->left!=NULL&&(root->left->data==n1||root->left->data==n2))
        return root->data;
    else if(root->right!=NULL&&(root->right->data==n1||root->right->data==n2))
        return root->data;
    else if((n1<root->data&&n2>root->data)||(n1>root->data&&n2<root->data))
        return root->data;
    else if(n1<root->data&&n2<root->data)
        return LCA(root->left,n1,n2);
    else
        return LCA(root->right,n1,n2);
}
struct node* insert(struct node* root, int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    if(root==NULL)
    {
        root = temp;
    }
    else if(x<=root->data)
       root->left =  insert(root->left,x);
    else
        root->right = insert(root->right,x);
    return root;

}
int minE(struct node*root)
{
    if(root==NULL)
    {
         printf("Tree Empty");
         return -1;
    }

    struct node* temp = root;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp->data;

}
struct node* minEP(struct node*root)
{
    if(root==NULL)
    {
         printf("Tree Empty");
         return -1;
    }

    struct node* temp = root;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp;

}
int maxE(struct node* root)
{
    if(root ==NULL)
    {
        printf("Tree Empty");
        return -1;

    }
    struct node* temp = root;
    if(temp->right==NULL)
        return temp->data;
    else
        return maxE(temp->right);

}
int height(struct node* root)
{
    if(root==NULL)
        return -1;
    else
        return max(height(root->left),height(root->right)) + 1;

}
int max(int a, int b)
{
    return a>=b?a:b;
}

void preorder(struct node*root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);

}
void inorder(struct node*root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);

}
void postorder(struct node*root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);

}
int check(struct node* root)
{
    if(root==NULL)
        return 1;
   if(lesser(root->left,root->data)==1&&greater(root->right,root->data==1)&&check(root->left)==1&&check(root->right)==1)
    return 1;
   else
    return 0;


}
int lesser(struct node* root,int a)
{

    if(root==NULL)
        return 1;
    if(root->data<=a&&lesser(root->left,a)==1&&lesser(root->right,a))
        return 1;
    else
        return 0;

}
int greater(struct node* root, int a)
{
    if(root==NULL)
        return 1;
    if(root->data>a&&greater(root->left,a)==1&&greater(root->right,a))
        return 1;
    else
        return 0;

}
void BFT(struct node* root)
{

    int front = -1, rear = -1;
    struct node* temp, *Q[MAX];
    if(root==NULL)
        return;
    EnQ(Q,root,&front,&rear);
    while(!isQempty(&front,&rear))
    {
        temp = Q[front];
        if(temp->left!=NULL)
            EnQ(Q,temp->left,&front,&rear);
        if(temp->right!=NULL)
            EnQ(Q,temp->right,&front,&rear);
        temp = DeQ(Q,&front,&rear);
        printf("%d ",temp->data);
    }
    return;


}
void EnQ(struct node** Q,struct node* x,int* front, int *rear)
{
    if(*front==-1)
        *front=0;
    if(*rear<MAX)
    {
        (*rear)++;
        Q[*rear]=x;
    }

}
struct node* DeQ(struct node** Q,int* front, int *rear)
{
    struct node* pop;
    if(*front==-1||*front>*rear)
        return -1;
    pop = Q[*front];
    (*front)++;
    return pop;
}
int isQempty(int*front,int*rear)
{
    if(*front==-1||*front>*rear)
        return 1;
    else
        return 0;
}
int SumOfLeaves(struct node*root, int *sum)
{

    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
        *sum = *sum + root->data;
    SumOfLeaves(root->left,sum);
    SumOfLeaves(root->right,sum);
    return *sum;

}
struct node* deleten(struct node* root, int x)
{
 if(root==NULL)
    return root;
    if(x<root->data)
        root->left = deleten(root->left,x);
    else if(x>root->data)
        root->right = deleten(root->right,x);
    else
    {
        if(root->left==NULL&&root->right==NULL)
        {

            free(root);
            root = NULL;
            return root;

        }
        else if(root->left==NULL)
        {
            struct node* temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if(root->right==NULL)
        {
            struct node* temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else
        {
            struct node* temp = minEP(root->right);
            root->data = temp->data;
            root->right = deleten(root->right,temp->data);
            return root;
        }
    }

    return root;

}
int level(struct node* root, int value, int l)
{

    if(root==NULL)
        return 0;
    if(root->data==value)
        return l;
    int tlevel;
    tlevel = level(root->left,value,l+1);
    if(tlevel!=0)
        return tlevel;
    tlevel = level(root->right,value,l+1);
    return tlevel;

}
int sum(struct node *root)
{
   if(root == NULL)
     return 0;
   return sum(root->left) + root->data + sum(root->right);
}

/* returns 1 if sum property holds for the given
    node and both of its children */
int isSumTree(struct node* node)
{
    int ls, rs;

    /* If node is NULL or it's a leaf node then
       return true */
    if(node == NULL ||
            (node->left == NULL && node->right == NULL))
        return 1;

   /* Get sum of nodes in left and right subtrees */
   ls = sum(node->left);
   rs = sum(node->right);

   /* if the node and both of its children satisfy the
       property return 1 else 0*/
    if((node->data == ls + rs)&&
            isSumTree(node->left) &&
            isSumTree(node->right))
        return 1;

   return 0;
}

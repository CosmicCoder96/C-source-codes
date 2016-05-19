#include<stdio.h>
struct node {
int data;
struct node * next;
};
// This program covers all the functions of a singly linked link list and it's associated operations with it.
struct node* addatpos(struct node* start, int data, int pos);
struct node* create_list(struct node* start);
void display(struct node* start);
struct node* iReverse(struct node* start);

int main()
{
    struct node* start = NULL;
    int c,data, item, pos;
    while(1<2)
    {
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Add to empty list\n");
        printf("6.Add at end\n");
        printf("7.Add after node\n");
        printf("8.Add before node\n");
        printf("9.Add at position\n");
        printf("10.Delete\n");
        printf("11.Reverse using iterative approach\n");
        printf("12.Reverse using recursive approach\n");
        printf("13.Quit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
                start = create_list(start);
                break;
        case 2:
                display(start);
                break;
        case 3:
              //  count(start);
                break;
        case 4:
                printf("Enter the element to search for : \n");
                scanf("%d",&data);
              //  search(start,data);
                break;
        case 5:
                printf("Enter the element to be inserted\n");
                scanf("%d",&data);
              //  start = addatbeg(start,data);
                break;
        case 6:
                printf("Enter the element to be inserted\n");
                scanf("%d",&data);
                //start = addatend(start,data);
                break;
        case 7:
                printf("Enter the element to be inserted\n");
                scanf("%d",&data);
                printf("Enter the element after which to insert the element\n");
                scanf("%d",&item);
               // start = addafter(start,data,item);
        case 8:
                printf("Enter the element to be inserted\n");
                scanf("%d",&data);
                printf("Enter the element before which to insert the element\n");
                scanf("%d",&item);
               // start = addbefore(start,data,item);
        case 9:
                printf("Enter the element to be inserted\n");
                scanf("%d",&data);
                printf("Enter the position at which to insert the element\n");
                scanf("%d",&pos);
                start = addatpos(start,data,pos);
                break;
        case 10:
                printf("Enter the element to be deleted\n");
                scanf("%d",&data);
               // start = del(start,data);
                break;
        case 11:
                start = iReverse(start);
                break;
        case 12:
             //   start = Rreverse(start);
                break;
        case 13:
                exit(1);
        default:
                printf("Wrong choice\n");
        }
    }
}

struct node* addatpos(struct node* start,int data, int pos)
{

struct node* temp = (struct node *)malloc(sizeof(struct node));
 temp->data = data;
 if(pos==1){
    temp->next = start;
    start = temp;
    return start;
}
int i;
struct node* p = start;
for(i=1;i<pos-1&&p!=NULL;i++)
    p = p->next;
if(p==NULL)
{
    printf("\nInvalid Position\n");
    return start;
}

temp->next = p->next;
p->next = temp;
return start;
}

struct node* create_list(struct node* start)
{
    int i, n , data;
    printf("\nEnter the number of elements you want to enter\n");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    start =addatpos(start,a[i],i+1);
    return start;


}
void display(struct node* start)
{
    struct node *p = start;
    if(p==NULL){
        printf("list is empty");
        }
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n\n\n\n");
    return;

}
struct node* iReverse(struct node* start)
{
    struct node* prev, *ptr, *next1;
    prev = NULL;
    ptr  = start;
    while(ptr!=NULL)
    {
        next1=ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next1;
    }
    start = prev;
    return start;

}

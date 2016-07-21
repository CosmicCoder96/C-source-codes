#include<stdio.h>
struct stack{
int data[1001];
int top;
};
void push(struct stack *,int );
int pop(struct stack*);
int main()
{


    while(1)
    {
        int n,i,y=0,last,counter=1,counter2=0;
         struct stack s;
        s.top=-1;
        last = 0;

        scanf("%d",&n);
        if(n==0)
            break;
        int a[n],b[n],flag=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);

            if(a[i]==counter){
                b[counter2++]=a[i];
                counter++;
            }

            else if(s.data[s.top]==counter)
            {
                while(s.data[s.top]==counter)
                {
                b[counter2++] = pop(&s);
                counter++;//
                }
                push(&s,a[i]);

            }
            else
            {
                if(s.top!=-1&&s.data[s.top]<a[i])
                {
                    flag =1;
                }
                push(&s,a[i]);
            }


        }
        while(s.top!=-1)
            b[counter2++]=pop(&s);
        if(flag==0)
        printf("yes\n",counter2);
        else
            printf("no\n");


    }
}
void push(struct stack* s,int x)
{
    if((*s).top==1001)
        return;
    else
    {
        (*s).top= (*s).top + 1;
        (*s).data[(*s).top] = x;
    }
}
int pop(struct stack* s)
{
    if((*s).top==-1)
        return -1;
    else
    {
        int z = (*s).data[(*s).top];
        (*s).top= (*s).top -1;
        return z;

    }
}

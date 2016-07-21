#include<stdio.h>
#define SIZE 10000
struct stack
{
int top;
int data[SIZE];
};

int pop(struct stack*);
void push(struct stack*,int x);

int priority(char symbol)
{
	switch(symbol)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	default :
		return 0;
	}
}
int main()
{
   struct stack st;
   st.top=-1;
   int t;
   scanf("%d",&t);
   while(t--){
   char s[1000];
   char postfix[1000],infix[1000];
   char next;
   scanf("%s",s);
int l = strlen(s),i,x,c=0;
   for(i=0;i<l;i++)
   {
        if(s[i]=='(')
            push(&st,s[i]);
        else if(s[i]==')')
        {
            while((next=pop(&st))!='(')
					postfix[c++] = next;
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='%'||s[i]=='/'||s[i]=='^'||s[i]=='*')
        {

            while( st.top!=-1 &&  priority(st.data[st.top])>= priority(s[i]) )
					postfix[c++]=pop(&st);
				push(&st,s[i]);
        }
        else
                            postfix[c++]=s[i];




   }
   while(st.top!=-1)
		postfix[c++]=pop(&st);
	postfix[c]='\0';
	int l2 = strlen(postfix);
	for(i=0;i<l2;i++)
    {
        if(a[i]>='a'&&a[i]<='z')
            push(&st,a[i]);
        else
        {
            if(st.top<1)
                printf("error");
            else
            {
                op1=pop(&st);
                op2=pop(&st);
                char temp[100];
                temp[0]='(';
                temp[1]=op1;
                temp[2]=a[i];
                temp[3]=op2;
                temp[4]=')';
                temp[5]='\0';
                for(i=0;i<6;i+-)
            }
        }

    }
	printf("%s",infix);
   }
   return 0;
}
int pop(struct stack *a)
{
    int x;
    if(a->top==-1)
        printf("Stack underflow");
    else{
         x =  a->data[a->top];
        a->top--;
        return x;}

}
void push(struct stack *a, int x)
{

if(a->top==SIZE-1)
    printf("Stack Overflow");
else{
    a->top++;
    a->data[a->top] = x;
    //printf("Element pushed succesfully");
}}


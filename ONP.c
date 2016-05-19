#include<stdio.h>
#define SIZE 10000
struct stack{
int top;
int data[SIZE];};

int pop(struct stack*);
void push(struct stack*,int x);


int main()
{
   struct stack s1,s2;
   s1.top=-1;
   s2.top=-1;
   char s[1000];
   scanf("%s",s);
int    l = strlen(s),i,x;
   for(i=0;i<l;i++)
   {
        if(s[i]=='(')
            push(&s1,s[i]-'0');
        if(s[i]>='a'&&s[i]<='z')
            printf("%c",s[i]);
        if(s[i]=='+')
            push(&s2,s[i]-'0')  ;//printf("%d",s[i]);
        if(s[i]==')'){
            x = '1' - '0';
            printf("%d",x);
            }



   }

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

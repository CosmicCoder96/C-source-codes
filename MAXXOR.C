#include<stdio.h>
int main(){
int L,R,x,a=1;
scanf("%d %d",&L,&R);
x = L^R;
while(x!=0)
{
    x = x/2;
    a <<=1;

}
a--;
printf("%d",a);
return 0;}

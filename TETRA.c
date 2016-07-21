#include<stdio.h>
#include<math.h>
float heron(int a,int b,int c)
{
    float s = (float)(a+b+c)/2.0;
    float area = (float)sqrt((float)(s*(s-a)*(s-b)*(s-c)));
    return area;

}
int main()
{
    int t;
    int U,V,W,u,v,w,u1,v1,w1 ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d",&u,&v,&w,&U,&V,&W);

        u1 = v*v + w*w -U*U;
        v1 = w*w + u*u - V*V;
        w1 = u*u + v*v - W*W;
        float volume = sqrt(4*u*u*v*v*w*w-u*u*u1*u1-v*v*v1*v1-w*w*w1*w1+u1*v1*w1)/12.0;
        float r = (float)((volume)/(heron(u,v,U)+heron(v,w,W)+heron(u,w,V)+heron(U,V,W)))*3;
        printf("%.4f\n",r);
    }
}

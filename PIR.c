#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    double U,V,W,u,v,w,u1,v1,w1 ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&u,&v,&w,&W,&V,&U);

        u1 = v*v + w*w -U*U;
        v1 = w*w + u*u - V*V;
        w1 = u*u + v*v - W*W;
        double volume = (double)sqrt(4*u*u*v*v*w*w-u*u*u1*u1-v*v*v1*v1-w*w*w1*w1+u1*v1*w1)/12;
        printf("%.4lf\n",volume);
    }
}

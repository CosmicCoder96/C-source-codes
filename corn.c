#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    long long int t,n;
    float cmax, c;
    scanf("%lld",&t);
    n = t;
    while(t--){
char s[100],r[100],h[100],se[100];
scanf("%s",s);
int i=0,x=0,y=0,z=0;
float area,radius,seeds,height,length;
    while(s[i]!='e'){
    r[x]=s[i];
    i++;
    x++;
    }
    r[x]='\0';
    i++;
    while(s[i]!='e'){
        se[y]=s[i];
        i++;
        y++;
        }
        i++;
        se[y]='\0';

    while(s[i]!='\0'){
        h[z]=s[i];
        i++;
        z++;
        }
        h[z]='\0';
        //printf("%s %s %s ",r,se,h);
        radius = atof(r);
        height = atof(h);
        seeds = atof(se);
        length = sqrt(radius*radius + height*height);
        area = 3.1415*radius*length*seeds;

     printf("%.f\n",ceil(area));
        }

return 0;
}

#include<stdio.h>
int main()
{

    int CP,TP,CBS,WS,speed;
    char WD,c;
    scanf("%d %d %d %d %c",&CP,&TP,&CBS,&WS,&WD);
    if(CP<=TP)
        c='R';
    else
        c='L';

  //  printf("%c\n",c);
    if(WD==c)
        speed = CBS + WS;
    else
        speed = CBS - WS;
  //  printf("%d\n",speed);

    if(CP==TP)
        printf("0.000000");
    else if(speed<=0)
        printf("Impossible");
    else
        printf("%.6f",(float)abs(CP-TP)/speed);
    return 0;


}

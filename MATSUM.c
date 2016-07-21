#include<stdio.h>

int matrix[1024][1024]={0};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(matrix, 0, sizeof(matrix[0][0]) * 1024 * 1024);

        int n,x1,x2,y1,y2,sum=0,val,i,j;
        scanf("%d",&n);
//        goto x;
        char s[100];
        while(1){
        scanf("%s",s);
        if(s[1]=='E')
        {
            scanf("%d %d %d",&x1,&y1,&val);
            matrix[x1][y1]=val;
        }
        else if(s[1]=='U')
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            for(i=x1;i<=x2;i++)
            {
                for(j=y1;j<=y2;j++)
                {
                    sum+=matrix[i][j];
                }
            }
            printf("%d\n",sum);
            sum=0;


        }
        else
        {
            break;
        }
        }
        printf("\n");
    }


    return 0;
}

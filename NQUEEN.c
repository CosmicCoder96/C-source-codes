#include<stdio.h>

int nqueen(int n,char board[][n],int col)
{
    int i;
    if(col>=n)
        return 1;
    for(i=0;i<n;i++)
    {
        if(ToPlaceOrNotToPlace(n,board,i,col)==1)
        {
            board[i][col]='Q';
            if(nqueen(n,board,col+1)==1)
                return 1;
            board[i][col]='.';
        }
    }
    return 0;
}
int ToPlaceOrNotToPlace(int n, char board[][n], int row, int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i]=='Q')
            return 0;

    }
    for(i=row,j=col;i>=0&&j>=0;i--,j--)
    {
         if(board[i][j]=='Q')
            return 0;

    }
    for(i=row,j=col;j>=0&&i<=n;i++,j--)
    {
         if(board[i][j]=='Q')
            return 0;

    }
    return 1;
}
void printBoard(int n,char board[][n])
{
    int i,j;
    for(i=0;i<n;i++)
        printf("\t%d",i+1);
    printf("\n\n\n\n");
    for(i=0;i<n;i++)
    {
        printf("%d",i+1);
        for(j=0;j<n;j++)
        {
            printf("\t%c",board[i][j]);
        }
        printf("\n\n\n\n");
    }
}
int main()
{

    int n,i,j;
    scanf("%d",&n);
    char board[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            board[i][j] = '.';

        }
    }
    if(nqueen(n,board,0)==1)
        printBoard(n,board);
    else
        printf("\nNo Solution\n");

}

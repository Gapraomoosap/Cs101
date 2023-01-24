#include<stdio.h>
int main()
{
    int row , colum ;
    int low , corum ;
    scanf("%d %d",&row,&colum);
    low = row ;
    corum = colum ;
    int matrix[row][colum],cur;
    int patrix[low][corum],cul;
    
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < colum ; j++)
        {
            scanf("%d",&cur);
            matrix[i][j] =  cur;
        }

    }

    for(int i = 0 ; i < low ; i++)
    {
        for(int j = 0 ; j < corum ; j++)
        {
            scanf("%d",&cul);
            patrix[i][j] = cul;
        }

    }

    for(int i = 0 ; i < low ; i++)
    {
        for(int j = 0 ; j < corum ; j++)
        {
            matrix[i][j] = matrix[i][j] + patrix[i][j];
            printf("%d ",matrix[i][j]);
        }
        printf("\n");

    }








    return 0 ;
}
#include<stdio.h>
int main(){

    int row , colum ;
    scanf("%d %d",&row,&colum);
    int matrix[row][colum],cur;
    
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < colum ; j++)
        {
            scanf("%d",&cur);
            matrix[i][j] =  cur;
        }

    }

    for(int k = 0; k < row ; k++)
    {
        for(int l = 0 ; l < colum ; l ++)
        {
            printf("%d ",matrix[l][k]);

        }
        printf("\n");
    }

    // printf("hello");
    return 0 ;
}
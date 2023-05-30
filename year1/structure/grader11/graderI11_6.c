#include<stdio.h>
int main(){
    int r,c,i,j,q1=0,q2=0,q3=0,q4=0;
    scanf("%d %d",&r,&c);
    int array[r][c];
    for(i = 0; i < r ; i++)
    {
        for(j = 0 ; j < c ; j++)
        {
            scanf("%d",&array[i][j]);
        }
    }
    
    for(i = 0; i < r ; i++)
    {
        for(j = 0 ; j < c ; j++)
        {
            if(i < r/2 && j < c/2)
            {   
                q1 = q1+array[i][j];
            }
            else if(i < r/2 && j >= c/2)
            {
                q2 = q2+array[i][j];    
            }
            else if(i >= r/2 && j < c/2)
            {
               q3 = q3+ array[i][j];
            }
            else if(i >= r/2 && j >= c/2)
            {
                q4 = q4+ array[i][j];
            }

        }
    }
    if(q1 > q2 && q1 > q3 && q1 > q4)
    {
        printf("%d  ",q1);
    }
    else if(q2 > q1 && q2 > q3 && q2 > q4)
    {
        printf("%d  ",q2);
    }
    if(q3 > q1 && q3 > q2 && q3 > q4)
    {
        printf("%d  ",q3);
    }
    if(q4 > q1 && q4 > q2 && q4 > q3)
    {
        printf("%d  ",q4);
    }

}
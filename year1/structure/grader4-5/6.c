#include <stdio.h>
int main(){
    int i , j , num,k ;
    scanf("%d",&num);
    for(i = 0;i<num;i++)
    {
        if(i == num -1 )
        {
            for(j=i+1;j<=num;j++)
            {
            printf("%d ",j);
            }
            for(k=1; i>0&&k<i+1;k++) 
            {
            printf("%d ",k);
            }
            break;
        }
        for(j=i+1;j<=num;j++)
        {
            printf("%d ",j);
        }
        for(k=1; i>0&&k<i+1;k++) 
        {

            printf("%d ",k);
        }
        printf("\n");
        

    }
    return 0 ;
}

#include<stdio.h>
int main()
{
    int n = 0 ,x;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++)
    {   
        x=i;
        for(int j = 1 ; j<= n ; j++)
        {
            if(x > n){
                x=1;
            }
            printf("%d",x);
            x++;
            
        }
        printf("\n");
    }

    return 0 ;
}
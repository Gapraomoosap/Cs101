#include <stdio.h>

int main()
{
    int x,total,sum = 0 ;
    int y[100000] = {0,1,1,2};
    scanf("%d", &x);
    if (x == 1 || x == 2)
    {
        printf("1");
    }
    else if(x == 0){
        printf("0");
    }
    else
    {
        for (int i =1; i <= x+1 ; i++)
        {
            if(i>3){
                y[i] = y[i-2] + y[i-1];
            }
        total = y[i-1];
        }
        printf("%d",total);
        
    }

    return 0;
}
#include<stdio.h>
int main ()
{
    int x,y,z ;
    scanf("%d %d",&x,&y);
    if(x-y > 0)
    {
        
        for(int i = x; i > 0 ; i-- )
        {
            
            if(x % i == 0 && y % i == 0)
            {
                printf("%d",i);
                
                break;

            }
        }
    }
    else
    {
        for(int i = y; i > 0 ; i-- )
        {
            if(x % i == 0 && y % i == 0)
            {
                printf("%d",i);
                break;

            }
        }

    }

}
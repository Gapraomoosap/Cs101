#include<stdio.h>
int main (){
    int num ;
    int ans[8] = {1,2,3,4,5,6,7,8} ;
    scanf("%d",&num);
    if(num %2 == 0)
    {
        ans[0] = 1;
        ans[1] = 0;
    }
     
    else 
    {
        ans[0] = 0;
        ans[1] = 1;
    }



    if(num % 2 != 0 && num % 3 == 0)
    {
        ans[2] = 0;
    }
    else if (num % 2 != 0 && num % 3 != 0)
    {
        ans[2] = 1;
    }
    else if (num % 2 == 0 && num % 4 == 0)
    {
        ans[2] = 0;
    }
    else if (num % 2 == 0 && num % 4 != 0)
    {
        ans[2] = 1;
    }


    if(num % 2 != 0 && num % 5 == 0)
    {
        ans[3] = 0;
    }
    else if (num % 2 != 0 && num % 5 != 0)
    {
        ans[3] = 1;
    }
    else if (num % 2 == 0 && num % 6 == 0)
    {
        ans[3] = 0;
    }
    else if (num % 2 == 0 && num % 6 != 0)
    {
        ans[3] = 1;
    }

    if(num > 10)
    {
        ans[4] = 0;
    }
    else 
    {
        ans[4] = 1;
    }

    if(num > 100)
    {
        ans[5] = 0;
    }
    else 
    {
        ans[5] = 1;
    }

    if(num > 1000)
    {
        ans[6] = 0;
    }
    else 
    {
        ans[6] = 1;
    }

    if(num > 10000)
    {
        ans[7] = 0;
    }
    else 
    {
        ans[7] = 1;
    }
    

    
    for(int i = 0; i<8;i++)
    {
        printf("%d",ans[i]);
    }







    return 0 ;    
}
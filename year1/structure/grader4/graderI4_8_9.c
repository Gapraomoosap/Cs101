#include<stdio.h>
int main (){
    int num ,max =0 ,flag=0;
    
    while(1)
    {
        scanf("%d",&num);
        if(num == 0)
        {
            break;
        }
        else
        {   
            flag = 0;
            for(int i = num-1; i > 1; i--)
            {
                if(num % i == 0 )
                {
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
                
                // printf("num = %d  / %d\n",num,i);
                
            }
            if(num == 2)
            {
                flag = 1;
            }
            // printf("flag = %d && num = %d",flag,num);
            if(flag == 1 && max < num)
            {
                max = num ; 
            }

        }

    }
    if(max == 0){
        max = -1;
    }

    printf("%d ",max);


    return 0 ;
}
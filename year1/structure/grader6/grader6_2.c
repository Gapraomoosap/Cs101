#include<stdio.h>
int main (){

    int pre =0  , max , keep ,count;
    while(1)
    {
        scanf("%d",&keep);
        if(keep ==  0)
        {
            break ;
        }

        if(keep > pre)
        {
            pre = keep ;
            count = 1;
        }
        else if (keep == pre)
        {
            count++;
        }



    }
    printf("%d %d ",pre,count);


    return 0 ;
}
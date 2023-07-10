#include <stdio.h>
int main()
{
    int big, small, req_big, req_small, cal_small, cal_big,total,check = 0;
    scanf("%d %d", &small, &big);
    scanf("%d %d", &req_small, &req_big);
    
    if((small == 0 && req_small > 0)||(big == 0 && req_big > 0 ))
    {
        
        check =1 ;
    }

    if (big == 0  )
    {
        big = 1;
    }
    if (small == 0)
    {
        small = 1;
    }
    
    cal_small = req_small / (small * 6);
    cal_big = req_big / (big * 10);
    
    
    if (req_small % (small * 6) != 0)
    {
        cal_small = cal_small + 1;
    }
    if (req_big % (big * 10) != 0)
    {
        cal_big = cal_big + 1;
    }

    if (cal_big > cal_small)
    {
        total = cal_big;
    }
    else if (cal_small > cal_big)
    {
        total = cal_small;
    }
    else
    {
        total = cal_big;
    }
    if(check == 1)
    {
        printf("Unable to finish order");
    }
    else 
    {
        printf("%d",total);
    }

    return 0;
}
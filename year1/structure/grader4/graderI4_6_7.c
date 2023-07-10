#include <stdio.h>
int main()
{
    int num, keep, flag,j,i;
    char str[1000];
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%d", &keep);

        flag = 0;
        for (j = keep - 1; j > 1; j--)
        {
            
            if (keep % j == 0)
            {
                
                flag = 1;
            }
        }

        
        if(flag == 1 || keep == 1||keep == 0)
        {
            str[i] = 'n';
            
        }
        else if(flag == 0 || keep == 2)
        {
            str[i] = 'y';
            
        }

    }
        for(int j = 0;j<num;j++)
        {
            printf("%c\n",str[j]);
        }
    
    return 0;
}
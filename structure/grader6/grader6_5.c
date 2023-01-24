#include <stdio.h>
#include <math.h>
int main()
{

    int num ,pos1,pos2 ;
    float Xcheck,Ycheck,final,max=10000000000000.00,x = 0.00, y = 0.00;
    scanf("%d", &num);
    float point[num][2];
    for (int i = 0; i < num; i++)
    {
        scanf("%f %f", &x, &y);
        point[i][0] = x;
        point[i][1] = y;
    }

    // for (int k = 0; k < num; k++)
    // {
    //     for (int l = 0; l < 2; l++)
    //     {
    //         printf("point[%d][%d] = %d ", k + 1, l, point[k][l]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < num; i++)
    {
        for(int j = i+1 ; j < num ; j++)
        {
            Xcheck = pow(point[i][0] - point[j][0],2);
            Ycheck = pow(point[i][1] - point[j][1],2);
            final = sqrt(Xcheck+Ycheck);
            
            if(final < max)
            {
                max = final;
                pos1 = i+1;
                pos2 = j+1;
                // printf("point = ")
                

            }
            

            // printf("point %d %d X = %d Y = %d X-Y = %d %d \n",i,j,point[i][0],point[j][0],Xcheck,Ycheck);
        }
    }

    printf("%d %d %.2f",pos1,pos2,max);
    return 0;
    
}
#include <stdio.h>
#include <math.h>
int main()
{
    int num = 0, xi = 0  ;
    float total = 0.00,xbar = 0.00,sum_pow = 0.00 ;
    int knum[1000];
    scanf("%d", &num);
    for (int i = 0; num > i; i++)
    {
        scanf("%d", &xi);
        knum[i] = xi;
        xbar = xbar + xi;
    }
    xbar = xbar / num;

    for (int j = 0; num > j; j++)
    {

        sum_pow = sum_pow + pow((knum[j] - xbar), 2);
        // printf("xi%d = %d \n",j+1,knum[j]);
    }
    total = sqrtf(sum_pow / (num-1));
    printf("%.2f",total);
    
}
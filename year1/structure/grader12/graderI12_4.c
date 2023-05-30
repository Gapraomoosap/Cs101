#include<stdio.h>
#include<math.h>
int main()
{
    int j,x,i,sum=0;
    scanf("%d %d",&x,&i);
    for(j = 0 ; j <= i ; j++)
    {
        sum = sum + pow(x,j);
    }
    printf("%d",sum);
}
#include<stdio.h>
int main()
{
    int x = 0 ,sum =0;
    scanf("%d",&x);
    for(int i = 0 ; i < x+1 ; i++)
    {
        sum += i;
    }
    printf("%d\n",sum);

    return 0 ;
}
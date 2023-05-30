#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char num;
    char icon;
    int flag;
} Card;

int main()
{
    int i,n,sum=0,j,pmax;
    char nmax,imax;
    scanf("%d",&n);
    Card array[n];
    for(i = 0; i < n; i++)
    {
        scanf("%s %s",&array[i].num,&array[i].icon);
        if (array[i].num == 'A')
        {
            array[i].flag = 1;
        }
        else if(array[i].num == '2')
        {
            array[i].flag = 2;
        }
        else if(array[i].num == '3')
        {
            array[i].flag = 3;
        }
        else if(array[i].num == '4')
        {
            array[i].flag = 4;
        }
        else if(array[i].num == '5')
        {
            array[i].flag = 5;
        }
        else if(array[i].num == '6')
        {
            array[i].flag = 6;
        }
        else if(array[i].num == '7')
        {
            array[i].flag = 7;
        }
        else if(array[i].num == '8')
        {
            array[i].flag = 8;
        }
        else if(array[i].num == '9')
        {
            array[i].flag = 9;
        }
        else if (array[i].num == 'J')
        {
            array[i].flag = 10;
        }
        else if (array[i].num == 'Q')
        {
            array[i].flag = 11;
        }
        else if (array[i].num == 'K')
        {
            array[i].flag = 12;
        }
    }
    for(i = 0 ; i < n ; i++)
    {
        sum = sum + array[i].flag;
    }
    for(i = 0 ; i < n ; i++)
    {
        for(j = i ; j < n ; j++)
        {
            if(array[i].flag >array[j].flag)
            {
                pmax = array[j].flag;
                array[j].flag = array[i].flag;
                array[i].flag = pmax;

                nmax = array[j].num;
                array[j].num = array[i].num;
                array[i].num = nmax;

                imax = array[j].icon;
                array[j].icon = array[i].icon;
                array[i].icon = imax;
            }
        }
    }
    for(i = 0 ; i < n ; i++)
    {
        printf("%c-%c",array[i].num , array[i].icon);
        if(i != n-1)
        {
            printf(", ");
        }
    }
    
    printf("\n%d",sum);
}
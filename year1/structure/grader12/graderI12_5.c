#include<stdio.h>
#include<math.h>
int main ()
{
    int n,i,a[100];
    scanf("%d %d %d",&n,&a[0],&a[1]);
    for(i = 0 ; i <= n ; i++)
    {
        if(i>1)
        {
            a[i] = (pow(i,2)*a[i-1]-a[i-2]+pow(3,i)); 
        }
        printf("%d ",a[i]);
    }
}
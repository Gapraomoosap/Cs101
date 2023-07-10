#include <stdio.h>
int main(){
int n,i,sum=0,keep=0; 
int start[] = {3,1};
scanf("%d",&n);
for(i = 0 ; i < n ; i++)
{
    // printf("sum = %d\n",sum);
    sum = sum + (start[0] * start[1]);
    keep = start[0];
    start[0] = start[0]+start[1];
    start[1] = keep-start[1];

}
printf("%d",sum);


}
#include<stdio.h>
int main() {

    int n,i,x,y;
    float sum ;
    scanf("%d",&n);
   
    for(i=0;i<n; i++ )
    
    {
        scanf("%d %d",&x,&y);
        sum = sum + ((x)*(y/60.0));
       
    }
    printf("%.1f",sum);
        // printf("Hello");
    return 0 ;

}
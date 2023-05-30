#include<stdio.h>
#include<math.h>
typedef struct 
{
    int x , y ;
}POINT;

int main(){
    int n ;
    float distance;
    scanf("%d",&n);
    POINT a[n];
    for(int i = 0 ; i<n ; i++){
        scanf("%d %d",&a[i].x ,&a[i].y);
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i].x >= 0 && a[i].y >= 0)
        {
            printf("1\n");
        }
        if(a[i].x < 0 && a[i].y >= 0)
        {
            printf("2\n");
        }
        if(a[i].x < 0 && a[i].y < 0)
        {
            printf("3\n");
        }
        if(a[i].x >= 0 && a[i].y < 0)
        {
            printf("4\n");
        }
    }
    distance=sqrt(pow(a[0].x-a[1].x,2)+pow(a[0].y-a[1].y,2));
	printf("%.0f\n",distance);

}


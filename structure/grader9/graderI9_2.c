#include<stdio.h>
#include<math.h>
typedef struct 
{
    float x,y,z;
}Vector;

int main(){
    int n ;
    float ans[100];
    scanf("%d",&n);
    Vector point;
    for(int i = 0 ; i<n ; i++)
    {
        scanf("%f %f %f",&point.x,&point.y,&point.z);
        ans[i] = sqrt((point.x*point.x)+(point.y*point.y)+(point.z*point.z));
    }
    for(int j = 0 ; j<n ; j++)
    {
        printf("%.2f\n",ans[j]);
    }
}

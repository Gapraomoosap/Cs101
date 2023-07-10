#include<stdio.h>
#include<math.h>

typedef struct{
    float x,y,z;
}Point;

int main()
{
    int n,i,j,count;
    float ans[100] ,pmax;
    scanf("%d",&n);
    Point array[n]; 
    for(i = 0 ; i < n ; i++)
    {
        scanf("%f %f %f",&array[i].x,&array[i].y,&array[i].z);
    }
    
    count = 0;
    for(i = 0 ; i < n ; i++)
    {
        for(j = i+1 ; j < n ; j++)
        {
            ans[count++] = sqrt(pow((array[j].x-array[i].x),2)+pow((array[j].y-array[i].y),2)+pow((array[j].z-array[i].z),2));   
        }
    }
    
    for(i = 0 ; i < count ; i++)
    {
        for(j = i+1 ; j < count ; j++)
        {
            if(ans[i]<ans[j])
            {
                pmax = ans[j];
                ans[j] = ans[i];
                ans[i] = pmax;
            }
        }   
    }
    
    for(i = 0 ; i < 3 ; i++){
        printf("%.2f\n",ans[i]);
    }
    
}

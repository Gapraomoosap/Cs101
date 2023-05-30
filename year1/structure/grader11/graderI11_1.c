#include<stdio.h>
typedef struct
{
    int morning,night ;
}Time;

int main(){
    int i ;
    float sum,msum,nsum; 
    float promo1,promo2,promo3;
    float p_morning,p_night,total_price1; 
    Time tel[100];
    for(i = 0 ; i < 4 ; i++)
    {
        scanf("%d %d",&tel[i].morning,&tel[i].night);
        sum = sum + tel[i].morning + tel[i].night;
        msum = msum + tel[i].morning;
        nsum = nsum + tel[i].night;
    }
    
    if(sum>1200)
    {
        promo3 = 600 + (1.25*(sum-1200));
    }
    else
    {
        promo3 = 600;
    }
     if(sum>500)
    {
        promo2 = 300 + (1.5*(sum-500));
    }
    else
    {
        promo2 = 300;
    }
    
    p_morning = msum * 0.75 ;
    p_night = nsum * 1.25 ;
    promo1 = p_morning + p_night ;
    
    if(promo1 < promo2 && promo1 < promo3){
        printf("1");
    }
    if(promo2 < promo1 && promo2 < promo3){
        printf("2");
    }
    if(promo3 < promo1 && promo3 < promo2){
        printf("3");
    }
}

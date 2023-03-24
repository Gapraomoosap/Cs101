#include<stdio.h>
int main(){
    int n,i,j,array[100],pos[100],neg[100],count_n=0,count_p=0,les_,sum_n=1,sum_p=1;
    scanf("%d",&n);
    for(i = 0 ; i < n ; i++){
        scanf("%d",&array[i]);
        if(array[i]>0)
        {
            pos[count_p] = array[i];
            count_p++;
        }
        else if(array[i]<0)
        {
            neg[count_n] = array[i];
            count_n++;    
        }
    }
    for(i = 0 ; i < count_n;i++)
    {
        for(j = i + 1 ; j < count_n ; j++)
        {
            if(neg[i] > neg[j]){
                les_ = neg[i];
                neg[i] = neg[j];
                neg[j] = les_;
            }
        }
    }
    for(i = 0 ; i < count_p ; i++)
    {
        sum_p = sum_p*pos[i];
    }
    if(count_n % 2 == 0 )
    {
        for(i = 0 ; i < count_n ; i++)
        {
            sum_n = sum_n * neg[i];
        }
    }
    else
    {
        for(i = 0 ; i < (count_n/2)+1 ; i++)
        {
            sum_n = sum_n * neg[i];
        }
    }
    if(sum_p * sum_n > sum_p){
        printf("%d",sum_p*sum_n);
    }
    else
    {
        printf("%d",sum_p);
    }
}
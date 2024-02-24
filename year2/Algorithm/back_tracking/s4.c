#include<stdio.h>

int cut_list[1000];
int n,L,min_no = 1000;
int flag = 0;
void backtracking(int total,int count)
{
    int i =0;
    if(total == L){
        if(count < min_no)
            min_no = count;
            flag = 1;
        return;
    }
    if(total > L || count >= min_no)
        return;

    for(i =0;i < n;i++){
        backtracking(total + cut_list[i],count+1);
    }
}

void main(){
    int i;
    scanf("%d %d",&L,&n);
    for(i = 0;i<n;i++){
        scanf("%d",&cut_list[i]);
    }
    backtracking(0,0);
    if(flag == 0)
        min_no = -1;
    printf("%d",min_no);
}
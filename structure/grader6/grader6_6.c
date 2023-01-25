#include<stdio.h>
int main(){
    int x , y , rent , round , people ,E_rent,J_rent,total_rent;
    scanf("%d %d",&x,&y);
    scanf("%d %d",&rent,&round);
    scanf("%d",&people);
    int matrix[x][y];
    for(int i = 0 ; i < x ; i++)
    {
        for(int j = 0 ; j < y ; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }

    
    for(int i = 0 ; i < x ; i++)
    {
        for(int j = 0 ; j < y ; j++)
        {
            E_rent = E_rent + matrix[i][j];
            
        }
        
    }
    J_rent = rent * round * people ;
    total_rent = J_rent + E_rent;
    if(total_rent % people != 0)
    {
        printf("%d",(total_rent/people)+1);
    }
    else
    {
        printf("%d",(total_rent/people));
    }
    
    

    



    return 0 ;
}
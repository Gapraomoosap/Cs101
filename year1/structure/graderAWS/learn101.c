#include<stdio.h>
int main(){
    

    // 1.0-----------------------------------------------------------

    // int x ;
    // scanf("%d",&x);
    // for(int i = 1 ; i <= x ; i++)
    // {
  
    //     for(int j = 0 ; j < i ; j++)
    //     {
    //         printf("*");
    //     }
    //     printf("\n");
    // }
    // for(int k = x-1 ; k >= 0 ; k--)
    // {
    //     for(int l = k ; l >0 ; l--){
    //         printf("*");
    //     }
    //     printf("\n");
    // }
    //-----------------------------------------------------------------
    


    // char A[10];
    // scanf("%s %c")

    // %s = "cs560 ieofs" =1 
    // %c = "A","2","*" = 1
    
    // int x[10] = {1,2,3,4,5,10,23,45,90};
    // //          {0,1,2,3,4,5,6,7,8,9}
    // int Num;
    //     for(int i  = 0 ; i<10 ;i++)
    //     {
    //         scanf("%d",Num);
    //         x[i] = Num ;
    //     }

    //     for(int i  = 0 ; i<10 ;i++)
    //     {
    //         printf("%d",x[i]);
    //     }
//     int Inp;
//     scanf("%d",&Inp);
//     int x[Inp][Inp],y[Inp][Inp];
//     int z[Inp][Inp];
    
//     int num ;
//     for(int i = 0; i<2 ; i++)
//     {
//         for(int j = 0 ; j<2 ; j++)
//         {
//             scanf("%d",&num);
//             x[i][j] = num;
//         }
//     }

//     for(int i = 0; i<2 ; i++)
//     {
//         for(int j = 0 ; j<2 ; j++)
//         {
//             scanf("%d",&num);
//             y[i][j] = num;
//         }
//     }

//     for(int i = 0; i<2 ; i++)
//     {
//         for(int j = 0 ; j<2 ; j++)
//         {
//             z[i][j] = x[i][j] + y[i][j];
//         }
//     }
//     printf("Result = : \n");
//     for(int i = 0; i<2 ; i++)
//     {
//         for(int j = 0 ; j<2 ; j++)
//         {
//             printf("%d ",z[j][i]);

//         }
//         printf("\n");
        
//     }


// char Array[900000] ;
// int Array[10];
// int num ; 
// // input = 1,2,3,4,5
//         // 0,1,2,3,4
// for(int i = 0 ; i < 10 ;i++)
// {
//     scanf("%d",&num);
//     Array[i] = num ;
// }

// int Array2[3][3] ;
// int Array3[3][3] ;
// int ArrayA[3][3] ;

// for(int i = 0 ; i < 3;i++ )
// {
//     for(int j = 0 ; j<3 ; j++)
//     {
//         scanf("%d",&num);
//         Array2[i][j] = num ;
//     }
// }


// for(int i = 0 ; i < 3;i++ )
// {
//     for(int j = 0 ; j<3 ; j++)
//     {
//         scanf("%d",&num);
//         Array3[i][j] = num ;
//     }
// }



// for(int i = 0 ; i < 3;i++ )
// {
//     for(int j = 0 ; j<3 ; j++)
//     {
//         ArrayA[i][j] = Array2[i][j]+Array3[i][j] ; 
//     }
// }



// for(int i = 0 ; i < 3;i++ )
// {
//     for(int j = 0 ; j<2 ; j++)
//     {
//         printf("%d",ArrayA[i][j]);
//     }
// }




// for(int i = 0 ; i < 3;i++ )
// {
//     for(int j = 0 ; j<2 ; j++)
//     {
//         printf("%d",ArrayA[j][i]);
//     }
// }



int Num,i,Prm,Max =0;
while(1)
{
    scanf("%d",&Num) ;
    for(i = 2 ; i < Num-1 ; i++)
    {
        if(Num%i==0)
        {
            Prm = 0 ;
            break;
        }
        else
        {
            Prm = 1;
        }
    }
    if(Prm == 1 && Num > Max)
    {
        Max = Num ;
    }
    
    if(Num == 0 )
    {
        break;
    }

}
if(Max == 0)
{
    printf("-1");
}
else{
    printf("%d",Max);
}

























    return 0 ;
}
#include<stdio.h>
#include<string.h>
void main(){
    char s[100];
    scanf("%[^\n]",s);
   
    int len0fstr = 0,i = 0,count_num=0;
    for(i=0 ; i < 100 ; i++)
    {
        if( s[i] == '\0'  )
        {
            break;
        }
        if( s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' ||
            s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9' )
        {
            count_num++;
        }
       
        len0fstr++;
    }
    for(i=len0fstr-1 ; i >=0 ; i--)
    {
        printf("%c",s[i]);
    }    
    printf("\n%d",count_num);
    
}


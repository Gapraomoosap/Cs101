#include<stdio.h>

int main() {
    int sum =0 ,m = 10;
    char str[10];
    scanf("%s", str);
    for (int i = 0; i < 10; i++)
    {
        sum = sum + ((str[i]-'0')*m);
        // printf("string = %c m = %d weight = %d sum = %d \n",str[i],m,(str[i]-'0')*m,sum);
        m--;
    }
    if (sum % 11 == 0)
    {
        printf("valid");
    }
    else
    {
        printf("invalid");
    }
    
    return 0;
}

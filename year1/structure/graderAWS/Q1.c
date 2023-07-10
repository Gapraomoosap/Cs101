#include <stdio.h>
#include <string.h>

int main()
{
    // char strings[100], cha_[100];
    // scanf("%s", strings);
    // for (int i = 0; i < strlen(strings); i++)
    // {
    //     cha_[i] = strings[i];
    // }
    // for (int i = strlen(strings) - 1; i >= 0; i--)
    // {
    //     printf("%c", cha_[i]);
    // }
    // return 0;

    
    #include <stdio.h>
    #include <ctype.h>
    #include <string.h>

    
    char string[100];

    printf("Enter a string in lowercase: ");
    scanf("%s", string);

    // Convert the string to uppercase
    for (int i = 0; i < strlen(string); i++) {
        string[i] = toupper(string[i]);
    }

    printf("The uppercase string is: %s\n", string);

    return 0;
    


    

    // char *numberindex[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    // char number[] = {"0123456789"};
    // char inp[1000];
    // int flag = 0;
    // scanf("%s", inp);
    // for (int i = 0; inp[i] != 0; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         flag = 0;
    //         if (inp[i] == number[j])
    //         {
    //             printf("%s", numberindex[j]);
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag == 0)
    //     {
    //         printf("%c", inp[i]);
    //     }
    // }
}

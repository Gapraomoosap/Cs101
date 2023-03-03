#include <stdio.h>

int main()
{
    // char strings[10000], cha_[10000];
    // int count = 0;
    // scanf("%s", strings);
    // for (int i = 0; strings[i] != 0; i++)
    // {
    //     cha_[i] = strings[i];
    //     count++;
    // }
    // for (int i = count; i >= 0; i--)
    // {
    //     printf("%c", cha_[i]);
    // }
    // return 0;

    // char strings[] = {"abcdefghijklmnopqrstuvwxyz"} ;
    // char cha_[] ={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    // char inp[1000];
    // scanf("%[^\n]",inp);

    // for(int i = 0 ; inp[i] != 0 ; i++)
    // {
    //     // printf("%s\n",inp);
    //     for(int j = 0 ; j<26; j++)
    //     {
    //         // printf("inp %c check %c\n" ,inp[i],strings[j]);
    //         if(inp[i] == strings[j])
    //         {
    //             printf("%c",cha_[j]);
    //         }
    //         else if(inp[i] == ' ')
    //         {
    //             printf(" ");
    //             break;
    //         }

    //     }

    // }

    char *numberindex[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char number[] = {"0123456789"};
    char inp[1000];
    int flag = 0;
    scanf("%s", inp);
    for (int i = 0; inp[i] != 0; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            flag = 0;
            if (inp[i] == number[j])
            {
                printf("%s", numberindex[j]);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("%c", inp[i]);
        }
    }
}

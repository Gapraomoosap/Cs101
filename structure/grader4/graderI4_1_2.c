#include <stdio.h>

int main()
{
    int tc = 0;
    scanf("%d", &tc);

    int i = 0, j = 0;
    for (i = 0; i < tc; i++)
    {
        for (j = 0; j < (tc - 1 - i); j++)
        {
            printf(" ");
        }
        printf("*");
        if (i != 0)
        {
            for (j = 0; j < (i * 2 - 1); j++)
            {
                printf(" ");
            }
            printf("*");
        }
        for (j = 0; j < (tc - 1 - i); j++)
        {
            printf(" ");
        }

        printf("\n");
    }

    for (i = 0; i < (tc - 1); i++)
    {
        for (j = 0; j < (i + 1); j++)
        {
            printf(" ");
        }
        printf("*");
        if (i != (tc - 2))
        {
            for (j = ((tc - 2 - i) * 2 - 1); j > 0; j--)
            {
                printf(" ");
            }
            printf("*");
        }
        for (j = 0; j < i; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}

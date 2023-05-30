#include <stdio.h>

int main()
{
    int i, j, rows;

    scanf("%d", &rows);

    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (rows % 2 == 0)
            {
                if (i % 2 == 0)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            else
            {
                if (i % 2 == 0)
                {
                    printf(" ");
                }
                else
                {
                    printf("*");
                }
            }
        }
        printf("\n");
    }
    for (i = rows - 1; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            if (rows % 2 == 0)
            {
                if (i % 2 == 0)
                {
                    printf("*");
                }
                else
                {
                    printf("");
                }
            }
            else
            {
                if (i % 2 == 0)
                {
                    printf("");
                }
                else
                {
                    printf("*");
                }
            }
        }
        printf("\n");
    }
    return 0;
}